/****************************************************************************
Copyright (c) 2017 EM ALL Studio

http://www.emallstudio.com

****************************************************************************/
package org.cocos2dx.cpp;

import org.cocos2dx.lib.Cocos2dxActivity;
import android.content.pm.ActivityInfo;

public class ScreenOrientation extends Cocos2dxActivity {

    private static final int SCREEN_ORIENTATION_UNKNOWN = 0;
    private static final int SCREEN_ORIENTATION_UNSPECIFIED = 15;
    private static final int SCREEN_ORIENTATION_PORTRAIT = 1;
    private static final int SCREEN_ORIENTATION_REVERSE_PORTRAIT = 2;
    private static final int SCREEN_ORIENTATION_SENSOR_PORTRAIT = 3;
    private static final int SCREEN_ORIENTATION_LANDSCAPE = 4;
    private static final int SCREEN_ORIENTATION_REVERSE_LANDSCAPE = 8;
    private static final int SCREEN_ORIENTATION_SENSOR_LANDSCAPE = 12;
    private static final int SCREEN_ORIENTATION_NATIVE_ERROR = -1;

   /**
    * Change the desired orientation of this activity.
    * If the activity is currently in the foreground or otherwise impacting the screen orientation,
    * the screen will immediately be changed (possibly causing the activity to be restarted).
    * Otherwise, this will be used the next time the activity is visible.
    */
    public static void setOrientation(int requestedOrientation) {
        Cocos2dxActivity activity = (Cocos2dxActivity)getContext();
        if (activity != null) {
            switch(requestedOrientation) {
                case SCREEN_ORIENTATION_PORTRAIT:
                    activity.setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_PORTRAIT);
                    break;
                case SCREEN_ORIENTATION_REVERSE_PORTRAIT:
                    activity.setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_REVERSE_PORTRAIT);
                    break;
                case SCREEN_ORIENTATION_SENSOR_PORTRAIT:
                    activity.setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_SENSOR_PORTRAIT);
                    break;
                case SCREEN_ORIENTATION_LANDSCAPE:
                    activity.setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_LANDSCAPE);
                    break;
                case SCREEN_ORIENTATION_REVERSE_LANDSCAPE:
                    activity.setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_REVERSE_LANDSCAPE);
                    break;
                case SCREEN_ORIENTATION_SENSOR_LANDSCAPE:
                    activity.setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_SENSOR_LANDSCAPE);
                    break;
                default:
                    activity.setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_UNSPECIFIED);
                    break;
            }
        }
    }

    /**
    * Return the current requested orientation of the activity.
    * This will either be the orientation requested in its component's manifest, or the last requested orientation
    * given to setRequestedOrientation(int).
    */
    public static int getOrientation() {
        int orientation = SCREEN_ORIENTATION_NATIVE_ERROR;

        Cocos2dxActivity activity = (Cocos2dxActivity)getContext();
        if (activity != null) {
            int deviceOrientation = activity.getRequestedOrientation();
            switch(deviceOrientation) {
                case ActivityInfo.SCREEN_ORIENTATION_PORTRAIT:
                    orientation = SCREEN_ORIENTATION_PORTRAIT;
                    break;
                case ActivityInfo.SCREEN_ORIENTATION_REVERSE_PORTRAIT:
                    orientation = SCREEN_ORIENTATION_REVERSE_PORTRAIT;
                    break;
                case ActivityInfo.SCREEN_ORIENTATION_SENSOR_PORTRAIT:
                    orientation = SCREEN_ORIENTATION_SENSOR_PORTRAIT;
                    break;
                case ActivityInfo.SCREEN_ORIENTATION_LANDSCAPE:
                    orientation = SCREEN_ORIENTATION_LANDSCAPE;
                    break;
                case ActivityInfo.SCREEN_ORIENTATION_REVERSE_LANDSCAPE:
                    orientation = SCREEN_ORIENTATION_REVERSE_LANDSCAPE;
                    break;
                case ActivityInfo.SCREEN_ORIENTATION_SENSOR_LANDSCAPE:
                    orientation = SCREEN_ORIENTATION_SENSOR_LANDSCAPE;
                    break;
                case ActivityInfo.SCREEN_ORIENTATION_UNSPECIFIED:
                    orientation = SCREEN_ORIENTATION_UNSPECIFIED;
                    break;
                default:
                    orientation = SCREEN_ORIENTATION_UNKNOWN;
                    break;
            }
        }

        return orientation;
    }

    /**
    * Return the native orientation value.
    */
    public static int convertToNativeValue(int orientation) {
        int nativeOrientation;

        switch(orientation) {
            case SCREEN_ORIENTATION_PORTRAIT:
                nativeOrientation = ActivityInfo.SCREEN_ORIENTATION_PORTRAIT;
                break;
            case SCREEN_ORIENTATION_REVERSE_PORTRAIT:
                nativeOrientation = ActivityInfo.SCREEN_ORIENTATION_REVERSE_PORTRAIT;
                break;
            case SCREEN_ORIENTATION_SENSOR_PORTRAIT:
                nativeOrientation = ActivityInfo.SCREEN_ORIENTATION_SENSOR_PORTRAIT;
                break;
            case SCREEN_ORIENTATION_LANDSCAPE:
                nativeOrientation = ActivityInfo.SCREEN_ORIENTATION_LANDSCAPE;
                break;
            case SCREEN_ORIENTATION_REVERSE_LANDSCAPE:
                nativeOrientation = ActivityInfo.SCREEN_ORIENTATION_REVERSE_LANDSCAPE;
                break;
            case SCREEN_ORIENTATION_SENSOR_LANDSCAPE:
                nativeOrientation = ActivityInfo.SCREEN_ORIENTATION_SENSOR_LANDSCAPE;
                break;
            default:
                nativeOrientation = ActivityInfo.SCREEN_ORIENTATION_UNSPECIFIED;
                break;
            }

        return nativeOrientation;
    }

}
