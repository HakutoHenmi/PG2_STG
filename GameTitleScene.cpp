#include "GameTitleScene.h"
#include "GameSceneManager.h"
#include <Novice.h>

GameTitleScene::GameTitleScene()
    : nextScene_(-1)
{
}

GameTitleScene::~GameTitleScene() { }

void GameTitleScene::Initialize()
{
    nextScene_ = -1;
}

void GameTitleScene::Update(const char* keys, const char* preKeys)
{
    // SPACEキーでプレイシーンに切り替え
    if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
        nextScene_ = GameSceneManager::SCENE_PLAY;
    }
}

void GameTitleScene::Draw()
{
    Novice::ScreenPrintf(500, 400, "Title Scene: Press SPACE to start", nullptr);
}

void GameTitleScene::Finalize()
{
}

int GameTitleScene::GetNextScene() const
{
    return nextScene_;
}
