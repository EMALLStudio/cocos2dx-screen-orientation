#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
#import "../ScreenOrientation.h"

USING_NS_CC;

std::unique_ptr<ScreenOrientation> ScreenOrientation::m_instance;
std::once_flag ScreenOrientation::m_onceFlag;

ScreenOrientation::ScreenOrientation()
{
}

ScreenOrientation::~ScreenOrientation()
{
    m_instance = nullptr;
}

ScreenOrientation& ScreenOrientation::GetInstance()
{
    std::call_once(m_onceFlag,
        [] {
            m_instance.reset(new ScreenOrientation);
    });
    return *m_instance.get();
}

void ScreenOrientation::setOrientation(int requestedOrientation)
{
    orientation = requestedOrientation;    
    setRequestedOrientation(requestedOrientation);
}

int ScreenOrientation::getOrientation()
{
    return orientation;
}

void ScreenOrientation::setRequestedOrientation(int requestedOrientation)
{    
    int nativeOrientation;
    if (requestedOrientation > SCREEN_ORIENTATION_UNKNOWN && requestedOrientation != SCREEN_ORIENTATION_UNSPECIFIED) {

        switch(requestedOrientation) {
            case SCREEN_ORIENTATION_PORTRAIT:
            /// iOS has no sernsor equivalent like android, convert to portrait.
            case SCREEN_ORIENTATION_SENSOR_PORTRAIT:            
                nativeOrientation = UIDeviceOrientationPortrait;
                break;
            case SCREEN_ORIENTATION_REVERSE_PORTRAIT:
                nativeOrientation = UIDeviceOrientationPortraitUpsideDown;
                break;            
            case SCREEN_ORIENTATION_LANDSCAPE:
            /// iOS has no sernsor equivalent like android, convert to landscape right.
            case SCREEN_ORIENTATION_SENSOR_LANDSCAPE:            
                nativeOrientation = UIDeviceOrientationLandscapeRight;
                break;                                    
            case SCREEN_ORIENTATION_REVERSE_LANDSCAPE:
                nativeOrientation = UIDeviceOrientationLandscapeLeft;
                break;
        }

        [[NSOperationQueue mainQueue] addOperationWithBlock:^ {
        [[UIDevice currentDevice] setValue:[NSNumber numberWithInteger: nativeOrientation] forKey:@"orientation"];
        }]; 
    }
}

int ScreenOrientation::getRequestedOrientation()
{
    int orientationValue;

    UIDeviceOrientation deviceOrientation = [[UIDevice currentDevice] orientation];

    switch(deviceOrientation) {
        case UIDeviceOrientationPortrait:
            orientationValue = SCREEN_ORIENTATION_PORTRAIT;
            break;
        case UIDeviceOrientationPortraitUpsideDown:
            orientationValue = SCREEN_ORIENTATION_REVERSE_PORTRAIT;
            break;
        case UIDeviceOrientationLandscapeRight:
            orientationValue = SCREEN_ORIENTATION_LANDSCAPE;
            break;                                    
        case UIDeviceOrientationLandscapeLeft:
            orientationValue = SCREEN_ORIENTATION_REVERSE_LANDSCAPE;
            break;            
        default:
            orientationValue = SCREEN_ORIENTATION_NATIVE_ERROR;
            break;                        
    }    

    /// iOS has no sernsor equivalent like android, convert manually.
    if ((orientationValue == SCREEN_ORIENTATION_PORTRAIT || orientationValue == SCREEN_ORIENTATION_REVERSE_PORTRAIT)
        && orientation == SCREEN_ORIENTATION_SENSOR_PORTRAIT) {
            /// force to sensor value.
            orientationValue = SCREEN_ORIENTATION_SENSOR_PORTRAIT;
    }

    if ((orientationValue == SCREEN_ORIENTATION_LANDSCAPE || orientationValue == SCREEN_ORIENTATION_REVERSE_LANDSCAPE)
        && orientation == SCREEN_ORIENTATION_SENSOR_LANDSCAPE) {
            /// force to sensor value.
            orientationValue = SCREEN_ORIENTATION_SENSOR_LANDSCAPE;
    }
    
    return orientationValue;
}

int ScreenOrientation::convertToNativeValue(int requestedOrientation)
{
    int nativeOrientation;
    
    switch(requestedOrientation) {
        case SCREEN_ORIENTATION_PORTRAIT:
            nativeOrientation = UIInterfaceOrientationMaskPortrait;
            break;
        case SCREEN_ORIENTATION_REVERSE_PORTRAIT:
            nativeOrientation = UIInterfaceOrientationMaskPortraitUpsideDown;
            break;
        case SCREEN_ORIENTATION_SENSOR_PORTRAIT:
            nativeOrientation = (UIInterfaceOrientationMaskPortrait | UIInterfaceOrientationMaskPortraitUpsideDown);
            break;
        case SCREEN_ORIENTATION_LANDSCAPE:
            nativeOrientation = UIInterfaceOrientationMaskLandscapeLeft;
            break;                                    
        case SCREEN_ORIENTATION_REVERSE_LANDSCAPE:
            nativeOrientation = UIInterfaceOrientationMaskLandscapeRight;
            break;            
        case SCREEN_ORIENTATION_SENSOR_LANDSCAPE:
            nativeOrientation = (UIInterfaceOrientationMaskLandscapeLeft | UIInterfaceOrientationMaskLandscapeRight);
            break;
        case SCREEN_ORIENTATION_UNSPECIFIED:
            nativeOrientation = UIInterfaceOrientationMaskAll;
            break;
        default:
            nativeOrientation = SCREEN_ORIENTATION_NATIVE_ERROR;
            break;                        
    }

    return nativeOrientation;
}

#endif // CC_PLATFORM_IOS