#include <jni.h>
#include <string.h>
#include <dlfcn.h>
#include <android/log.h>
#include <unistd.h>
#include <sys/mman.h>

#define LOG_TAG "SkinHook"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

JNIEXPORT void JNICALL Java_com_standoff2_skinchanger_MainActivity_injectAllSkins(JNIEnv* env, jobject thiz) {
    LOGI("Injecting all skins (rootless mode)");

    // Oyun lib'sini bellekte bul
    void* handle = dlopen("libStandoff2.so", RTLD_NOW);
    if (!handle) {
        LOGI("libStandoff2.so bulunamadı, alternatif yöntem deneniyor");
        // Bellek taraması ile skin ID'leri bul
        for (int i = 0; i < 0x1000000; i += 4) {
            // Örnek: skin ID 101-200 arası zorla
            // Gerçek oyunda memory scanning ile bulunur
        }
        return;
    }

    // Oyun içi skin tablosunu override et
    void* skinTable = dlsym(handle, "_Z10GetSkinIDi"); // sembol ismi örnek
    if (skinTable) {
        // Kod patchleme (root gerekmez, çünkü kendi process)
        int pageSize = sysconf(_SC_PAGESIZE);
        void* pageAligned = (void*)((long)skinTable & ~(pageSize - 1));
        mprotect(pageAligned, pageSize, PROT_READ | PROT_WRITE | PROT_EXEC);
        // 0x90 (NOP) ile doldur veya return true yap
        memset(skinTable, 0x90, 8);
        LOGI("Skin table patched successfully");
    }

    dlclose(handle);
}
