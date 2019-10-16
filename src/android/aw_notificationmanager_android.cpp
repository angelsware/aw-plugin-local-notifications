#include "aw_notificationmanager_android.h"
#include <localnotifications/aw_notification.h>
#include <platform/android/aw_jni.h>
#include <platform/android/aw_jnifunction.h>
#include <platform/android/aw_jnistring.h>
#include <platform/android/aw_jnilongarray.h>
#include <rendering/aw_color.h>

namespace LocalNotifications {
	bool CNotificationManager_Android::initialize() {
		if (jclass clazz = Platform::CJniFunction::getClass("com/angelsware/localnotifications/NotificationManager")) {
			if (jmethodID method = Platform::CJniFunction::getMethod(clazz, "initialize", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;I)Z")) {
				Platform::CJniString channelId("aw_channel_id");
				Platform::CJniString channelName("aw_channel_name");
				Platform::CJniString channelDescription("aw_channel_description");
				int importance = 3; // NotificationManager.IMPORTANCE_DEFAULT
				return Platform::CJni::getEnv()->CallStaticBooleanMethod(clazz, method, channelId.getText(), channelName.getText(), channelDescription.getText(), importance);
			}
		}
		return false;
	}

	void CNotificationManager_Android::sendNotification(int id, const CNotification& notification) {
		if (jclass clazz = Platform::CJniFunction::getClass("com/angelsware/localnotifications/NotificationManager")) {
			if (jmethodID method = Platform::CJniFunction::getMethod(clazz, "sendNotification", "(Ljava/lang/String;ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;IIZ[JLjava/lang/String;)V")) {
				Platform::CJniString channelId("aw_channel_id");
				Platform::CJniString title(notification.getTitle());
				Platform::CJniString text(notification.getText());
				Platform::CJniString largeIcon(notification.getLargeIcon());
				Platform::CJniLongArray vibrationPattern(notification.getVibration().data(), static_cast<int>(notification.getVibration().getCount()));
				int priority = 0;
				int color = 0;
				bool autoCancel = true;

				Platform::CJniString payload(notification.getPayload());
				Platform::CJni::getEnv()->CallStaticVoidMethod(clazz, method, channelId.getText(), id, title.getText(), text.getText(), largeIcon.getText(), priority, color, autoCancel, vibrationPattern.getLongArray(), payload.getText());
			}
		}
	}

	void CNotificationManager_Android::addListener(INotificationListener* listener) {
		if (jclass clazz = Platform::CJniFunction::getClass("com/angelsware/localnotifications/NotificationManager")) {
			if (jmethodID method = Platform::CJniFunction::getMethod(clazz, "addListener", "(J)V")) {
				Platform::CJni::getEnv()->CallStaticVoidMethod(clazz, method, reinterpret_cast<jlong>(listener));
			}
		}
	}

	void CNotificationManager_Android::removeListener(INotificationListener* listener) {
		if (jclass clazz = Platform::CJniFunction::getClass("com/angelsware/localnotifications/NotificationManager")) {
			if (jmethodID method = Platform::CJniFunction::getMethod(clazz, "removeListener", "(J)V")) {
				Platform::CJni::getEnv()->CallStaticVoidMethod(clazz, method, reinterpret_cast<jlong>(listener));
			}
		}
	}

	void CNotificationManager_Android::clearAllListeners() {
		if (jclass clazz = Platform::CJniFunction::getClass("com/angelsware/localnotifications/NotificationManager")) {
			if (jmethodID method = Platform::CJniFunction::getMethod(clazz, "clearAllListeners", "()V")) {
				Platform::CJni::getEnv()->CallStaticVoidMethod(clazz, method);
			}
		}
	}
}
