#ifndef __AW_LOCAL_NOTIFICATIONS_NOTIFICATION_MANAGER_ANDROID_H__
#define __AW_LOCAL_NOTIFICATIONS_NOTIFICATION_MANAGER_ANDROID_H__

#include <localnotifications/aw_notificationmanager.h>

namespace LocalNotifications {
	class CNotificationManager_Android
		: public INotificationManager
	{
	private:
		bool initialize() override;
		void sendNotification(int id, const CNotification& notification) override;
		void addListener(INotificationListener* listener) override;
		void removeListener(INotificationListener* listener) override;
		void clearAllListeners() override;
	};
}

#endif
