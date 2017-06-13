#ifndef __SCREEN_ORIENTATION_H_
#define __SCREEN_ORIENTATION_H_

#include <memory>
#include <mutex>

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
#endif // (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC)

#ifndef SCREEN_ORIENTATION_UNKNOWN
#define SCREEN_ORIENTATION_UNKNOWN 0
#endif // SCREEN_ORIENTATION_UNKNOWN

#ifndef SCREEN_ORIENTATION_UNSPECIFIED
#define SCREEN_ORIENTATION_UNSPECIFIED 15
#endif // SCREEN_ORIENTATION_UNSPECIFIED

#ifndef SCREEN_ORIENTATION_PORTRAIT
#define SCREEN_ORIENTATION_PORTRAIT 1
#endif // SCREEN_ORIENTATION_PORTRAIT

#ifndef SCREEN_ORIENTATION_REVERSE_PORTRAIT
#define SCREEN_ORIENTATION_REVERSE_PORTRAIT 2
#endif // SCREEN_ORIENTATION_REVERSE_PORTRAIT

#ifndef SCREEN_ORIENTATION_SENSOR_PORTRAIT
#define SCREEN_ORIENTATION_SENSOR_PORTRAIT 3
#endif // SCREEN_ORIENTATION_SENSOR_PORTRAIT

#ifndef SCREEN_ORIENTATION_LANDSCAPE
#define SCREEN_ORIENTATION_LANDSCAPE 4
#endif // SCREEN_ORIENTATION_LANDSCAPE

#ifndef SCREEN_ORIENTATION_REVERSE_LANDSCAPE
#define SCREEN_ORIENTATION_REVERSE_LANDSCAPE 8
#endif // SCREEN_ORIENTATION_REVERSE_LANDSCAPE

#ifndef SCREEN_ORIENTATION_SENSOR_LANDSCAPE
#define SCREEN_ORIENTATION_SENSOR_LANDSCAPE 12
#endif // SCREEN_ORIENTATION_SENSOR_LANDSCAPE

#ifndef SCREEN_ORIENTATION_NATIVE_ERROR
#define SCREEN_ORIENTATION_NATIVE_ERROR -1
#endif // SCREEN_ORIENTATION_NATIVE_ERROR

class ScreenOrientation {
    public:
    virtual ~ScreenOrientation();
    /**
    @brief Get the current application instance.
    @return Current application instance pointer.
    */
    static ScreenOrientation& GetInstance();

    /**
    @brief Change the desired orientation.
    @param requestedOrientation ScreenOrientation class orientation value.
    */
    void setOrientation (int requestedOrientation);

    /**
    @brief Return the current orientation value.
    @return Current orientation value.
    */
    int getOrientation ();

    /**
    @brief Orientation state change native function.
    @param requestedOrientation ScreenOrientation class orientation value.
    */
    void setRequestedOrientation(int requestedOrientation);

    /**
    @brief Orientation state get native function.
    @return Current orientation value.
    */
    int getRequestedOrientation();

    /**
    @brief Converts ScreenOrientation class orientation value to native orientation value.
    @param requestedOrientation ScreenOrientation class orientation value.
    @return Native orientation value.
    */
    int convertToNativeValue(int requestedOrientation);

    private:
    /// ScreenOrientation class orientation value
    int orientation = SCREEN_ORIENTATION_UNSPECIFIED;

    /// instance ptr
    static std::unique_ptr<ScreenOrientation> m_instance;

    /// thread-safe flag
    static std::once_flag m_onceFlag;

    /// constructors and etc.
    ScreenOrientation(void);
    ScreenOrientation(const ScreenOrientation& src);
    ScreenOrientation& operator=(const ScreenOrientation& rhs);
};

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
#ifdef __cplusplus
}
#endif // __cplusplus
#endif // (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC)

#endif // __SCREEN_ORIENTATION_H_