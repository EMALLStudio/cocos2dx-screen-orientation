#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#include "../ScreenOrientation.h"
#include "platform/android/jni/JniHelper.h"

#define CLASS_NAME "org/cocos2dx/cpp/ScreenOrientation"


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
    /// Call java static void method
    JniMethodInfo methodInfo;
    if (JniHelper::getStaticMethodInfo(methodInfo,
                                       CLASS_NAME,
                                       "setOrientation",
                                       "(I)V"))
    {
        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, requestedOrientation);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
    }
}

int ScreenOrientation::getRequestedOrientation()
{
    /// Call java static int method
    JniMethodInfo methodInfo;
    if (JniHelper::getStaticMethodInfo(methodInfo,
                                       CLASS_NAME,
                                       "getOrientation",
                                       "()V"))
    {
        int result = methodInfo.env->CallStaticIntMethod(methodInfo.classID, methodInfo.methodID);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
        return result;
    }
    else
    {
        return SCREEN_ORIENTATION_NATIVE_ERROR;
    }
}

int ScreenOrientation::convertToNativeValue(int requestedOrientation)
{
    /// Call java static int method
    JniMethodInfo methodInfo;
    if (JniHelper::getStaticMethodInfo(methodInfo,
                                       CLASS_NAME,
                                       "convertToNativeValue",
                                       "(I)I"))
    {
        int result = methodInfo.env->CallStaticIntMethod(methodInfo.classID, methodInfo.methodID, requestedOrientation);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
        return result;
    }
    else
    {
        return SCREEN_ORIENTATION_NATIVE_ERROR;
    }
}

#endif // CC_PLATFORM_ANDROID