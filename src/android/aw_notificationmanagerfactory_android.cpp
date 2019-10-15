#include <localnotifications/aw_notificationmanagerfactory.h>
#include "aw_notificationmanager_android.h"

namespace LocalNotifications {
	INotificationManager* CNotificationManagerFactory::create() {
		return new CNotificationManager_Android();
	}

	void CNotificationManagerFactory::destroy(INotificationManager* notificationManager) {
		delete notificationManager;
	}
}
