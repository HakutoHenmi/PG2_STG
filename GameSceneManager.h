#pragma once
#include "IGameScene.h"

class GameSceneManager {
public:
    // シーン識別子、タイトル、プレイ、リザルト
    enum SceneID {
        SCENE_TITLE = 0,
        SCENE_PLAY,
        SCENE_RESULT
    };

    GameSceneManager();
    ~GameSceneManager();

    void ChangeScene(SceneID nextScene);
    void Update(const char* keys, const char* preKeys);
    void Draw();

private:
    IGameScene* currentScene_;
};