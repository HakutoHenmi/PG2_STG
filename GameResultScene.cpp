#include "GameResultScene.h"
#include "GamePlayScene.h"
#include "GameSceneManager.h"
#include <Novice.h>

GameResultScene::GameResultScene()
    : nextScene_(-1)
{
}

GameResultScene::~GameResultScene() { }

void GameResultScene::Initialize()
{
    nextScene_ = -1;
}

void GameResultScene::Update(const char* keys, const char* preKeys)
{
    // SPACEキーでタイトルシーンへ戻る
    if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
        nextScene_ = GameSceneManager::SCENE_TITLE;
    }
}

void GameResultScene::Draw()
{
    Novice::ScreenPrintf(500, 200, "Result Scene: Press SPACE to return to Title", nullptr);
    Novice::ScreenPrintf(500, 400, "Enemies defeated: %d", gEnemyKillCount);
}

void GameResultScene::Finalize()
{
    gEnemyKillCount = 0;
}

int GameResultScene::GetNextScene() const
{
    return nextScene_;
}
