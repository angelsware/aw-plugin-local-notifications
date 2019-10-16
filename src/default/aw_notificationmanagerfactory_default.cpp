#include <localnotifications/aw_notificationmanagerfactory.h>
#include "aw_notificationmanager_default.h"

namespace LocalNotifications {
	INotificationManager* CNotificationManagerFactory::create() {
		return new CNotificationManager_Default();
	}

	void CNotificationManagerFactory::destroy(INotificationManager* notificationManager) {
		delete notificationManager;
	}
}
