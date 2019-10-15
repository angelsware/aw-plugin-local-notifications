package com.angelsware.localnotifications.NotificationManager;

import android.app.PendingIntent;
import android.content.Context;

import android.app.NotificationChannel;
import android.content.Intent;
import android.content.res.AssetManager;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;

import androidx.core.app.NotificationCompat;
import androidx.core.app.NotificationManagerCompat;

import java.io.InputStream;

import com.angelsware.engine.AppActivity;

public class NotificationManager {
	public native void onNotification(int id, String data);

	public static boolean initialize(String channelId, String channelName, String channelDescription, int importance) {
		NotificationChannel notificationChannel = new NotificationChannel(channelId, channelName, importance);
		notificationChannel.setDescription(channelDescription);

		android.app.NotificationManager notificationManager = (android.app.NotificationManager) AppActivity.getActivity().getSystemService(Context.NOTIFICATION_SERVICE);
		if (notificationManager != null) {
			notificationManager.createNotificationChannel(notificationChannel);
			return true;
		}
		return false;
	}

	public static void sendNotification(String channelId, int id, String title, String text, String largeIcon, int priority, int color, boolean autoCancel, long[] vibrationPattern, String payload) {
		NotificationCompat.Builder builder = new NotificationCompat.Builder(AppActivity.getActivity(), channelId);
		//builder.setSmallIcon(R.drawable.ic_launcher);
		if (text != null) {
			builder.setContentText(text);
		}
		if (title != null) {
			builder.setContentTitle(title);
		}
		if (largeIcon != null) {
			Bitmap bitmap = getBitmapFromAsset(largeIcon);
			if (bitmap != null) {
				builder.setLargeIcon(bitmap);
			}
		}
		if (priority >= 0) {
			builder.setPriority(priority);
		}
		builder.setColor(color);
		if (vibrationPattern != null) {
			builder.setVibrate(vibrationPattern);
		}
		builder.setAutoCancel(autoCancel);

		Intent intent = new Intent(AppActivity.getActivity(), AppActivity.class);
		intent.putExtra("notification_id", id);
		if (payload != null) {
			intent.putExtra("notification_payload", payload);
		}
		PendingIntent pendingIntent = PendingIntent.getActivity(AppActivity.getActivity(), 0, intent, PendingIntent.FLAG_UPDATE_CURRENT);
		builder.setFullScreenIntent(pendingIntent, true);

		NotificationManagerCompat notificationManager = NotificationManagerCompat.from(AppActivity.getActivity());
		notificationManager.notify(id, builder.build());
	}

	private static Bitmap getBitmapFromAsset(String filePath) {
		Bitmap bitmap = null;
		try {
			AssetManager assetManager = AppActivity.getActivity().getAssets();
			if (assetManager != null) {
				InputStream inputStream = assetManager.open(filePath);
				bitmap = BitmapFactory.decodeStream(inputStream);
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
		return bitmap;
	}
}
