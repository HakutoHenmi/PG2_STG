#include "GameSceneManager.h"
#include "GamePlayScene.h"
#include "GameResultScene.h"
#include "GameTitleScene.h"

GameSceneManager::GameSceneManager()
    : currentScene_(nullptr)
{
}

GameSceneManager::~GameSceneManager()
{
    if (currentScene_) {
        currentScene_->Finalize();
        delete currentScene_;
    }
}

void GameSceneManager::ChangeScene(SceneID nextScene)
{
    if (currentScene_) {
        currentScene_->Finalize();
        delete currentScene_;
        currentScene_ = nullptr;
    }
    switch (nextScene) {
    case SCENE_TITLE:
        currentScene_ = new GameTitleScene();
        break;
    case SCENE_PLAY:
        currentScene_ = new GamePlayScene();
        break;
    case SCENE_RESULT:
        currentScene_ = new GameResultScene();
        break;
    default:
        break;
    }
    if (currentScene_) {
        currentScene_->Initialize();
    }
}

void GameSceneManager::Update(const char* keys, const char* preKeys)
{
    if (currentScene_) {
        currentScene_->Update(keys, preKeys);
        int nextScene = currentScene_->GetNextScene();
        if (nextScene != -1) {
            ChangeScene(static_cast<SceneID>(nextScene));
        }
    }
}

void GameSceneManager::Draw()
{
    if (currentScene_) {
        currentScene_->Draw();
    }
}
