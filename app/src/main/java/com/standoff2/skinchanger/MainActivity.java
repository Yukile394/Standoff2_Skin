package com.standoff2.skinchanger;

import android.app.Activity;
import android.os.Build;
import android.os.Bundle;
import android.widget.TextView;
import android.widget.Toast;
import android.os.Handler;

public class MainActivity extends Activity {
    static {
        System.loadLibrary("nativehook");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        TextView status = findViewById(R.id.statusText);
        status.setText("Skin Changer Aktif - Tüm Skinler Açıldı");

        // Bypass başlat
        BypassManager bypass = new BypassManager();
        bypass.initialize(this);

        // Oyunu beklemeden enjekte
        new Handler().postDelayed(() -> {
            Toast.makeText(this, "Enjeksiyon tamamlandı (rootsuz)", Toast.LENGTH_LONG).show();
            injectAllSkins();
        }, 2000);
    }

    private native void injectAllSkins(); // nativehook.c içinde
}
