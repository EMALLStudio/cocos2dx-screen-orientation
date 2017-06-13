/**
 * Dummy class
 */

#if (CC_TARGET_PLATFORM != CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM != CC_PLATFORM_IOS)

#include "../ScreenOrientation.h"

std::unique_ptr<ScreenOrientation> ScreenOrientation::m_instance;
std::once_flag ScreenOrientation::m_onceFlag;

ScreenOrientation::ScreenOrientation()
{
}

ScreenOrientation::~ScreenOrientation()
{
    m_instance = nullptr;
}

void ScreenOrientation::setOrientation(int requestedOrientation)
{
}

int ScreenOrientation::getOrientation()
{
    return SCREEN_ORIENTATION_NATIVE_ERROR;
}

void ScreenOrientation::setRequestedOrientation(int requestedOrientation)
{
}

int ScreenOrientation::getRequestedOrientation()
{
    return SCREEN_ORIENTATION_NATIVE_ERROR;
}

int ScreenOrientation::convertToNativeValue(int requestedOrientation)
{
    return SCREEN_ORIENTATION_NATIVE_ERROR;
}

ScreenOrientation& ScreenOrientation::GetInstance()
{
    std::call_once(m_onceFlag,
        [] {
            m_instance.reset(new ScreenOrientation);
    });
    return *m_instance.get();
}

#endif // (CC_TARGET_PLATFORM != CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM != CC_PLATFORM_IOS)
