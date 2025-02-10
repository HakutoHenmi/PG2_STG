#include "GameSceneManager.h"
#include <Novice.h>
#include <cstring>

const char kWindowTitle[] = "PG2_STG_LC1A_ヘンミ_ハクト";

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{

    Novice::Initialize(kWindowTitle, 1280, 720);

    char keys[256] = { 0 };
    char preKeys[256] = { 0 };

    // 初期シーンはタイトルシーン
    GameSceneManager sceneManager;
    sceneManager.ChangeScene(GameSceneManager::SCENE_TITLE);

    while (Novice::ProcessMessage() == 0) {
        Novice::BeginFrame();

        memcpy(preKeys, keys, sizeof(keys));
        Novice::GetHitKeyStateAll(keys);

        sceneManager.Update(keys, preKeys);
        sceneManager.Draw();

        Novice::EndFrame();

        if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0)
            break;
    }

    Novice::Finalize();
    return 0;
}