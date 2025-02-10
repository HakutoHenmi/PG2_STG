#include "GamePlayScene.h"
#include "GameSceneManager.h"
#include <Novice.h>
#include <cstdlib>

int gEnemyKillCount = 0;

GamePlayScene::GamePlayScene()
    : nextScene_(-1)
{
}

GamePlayScene::~GamePlayScene() { }

void GamePlayScene::Initialize()
{
    nextScene_ = -1;
    playerShip_.Initialize();

    enemies_.clear();
    // 5体の敵を生成
    for (int i = 0; i < 5; i++) {
        Game::EnemyShip enemy;
        enemy.Initialize();
        enemies_.push_back(enemy);
    }

    projectiles_.clear();
}

void GamePlayScene::Update(const char* keys, const char* preKeys)
{
    playerShip_.Update(keys, preKeys);

    // 敵の更新
    for (auto& enemy : enemies_) {
        enemy.Update();
        if (!enemy.IsActive()) {
            enemy.Respawn();
        }
    }

    // 弾の更新
    for (auto& proj : projectiles_) {
        proj.Update();
    }

    // スペースキーで弾発射
    if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
        Game::Projectile proj;
        proj.Initialize();
        // 自機の右側中央付近から発射
        proj.SetPosition(
            playerShip_.GetX() + static_cast<float>(playerShip_.GetWidth()),
            playerShip_.GetY() + static_cast<float>(playerShip_.GetHeight()) / 2.0f - static_cast<float>(proj.GetHeight()) / 2.0f);
        proj.SetActive(true);
        projectiles_.push_back(proj);
    }

    CheckCollisions();

    // ENTERキーでリザルトシーンへ切り替え
    if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
        nextScene_ = GameSceneManager::SCENE_RESULT;
    }
}

void GamePlayScene::Draw()
{
    playerShip_.Draw();
    for (const auto& enemy : enemies_) {
        enemy.Draw();
    }
    for (const auto& proj : projectiles_) {
        proj.Draw();
    }
}

void GamePlayScene::Finalize()
{
}

int GamePlayScene::GetNextScene() const
{
    return nextScene_;
}

// 当たり判定
bool GamePlayScene::CheckCollisionRect(float x1, float y1, float w1, float h1,
    float x2, float y2, float w2, float h2)
{
    return !(x1 + w1 < x2 || x1 > x2 + w2 || y1 + h1 < y2 || y1 > y2 + h2);
}

void GamePlayScene::CheckCollisions()
{
    // 自機と敵の当たり判定
    for (auto& enemy : enemies_) {
        if (enemy.IsActive() && CheckCollisionRect(playerShip_.GetX(), playerShip_.GetY(), static_cast<float>(playerShip_.GetWidth()), static_cast<float>(playerShip_.GetHeight()), enemy.GetX(), enemy.GetY(), static_cast<float>(enemy.GetWidth()), static_cast<float>(enemy.GetHeight()))) {
            // 自機と敵が衝突したらリザルトシーンへ
            nextScene_ = GameSceneManager::SCENE_RESULT;
        }
    }

    // 弾と敵の当たり判定
    for (auto& proj : projectiles_) {
        if (proj.IsActive()) {
            for (auto& enemy : enemies_) {
                if (enemy.IsActive() && CheckCollisionRect(proj.GetX(), proj.GetY(), static_cast<float>(proj.GetWidth()), static_cast<float>(proj.GetHeight()), enemy.GetX(), enemy.GetY(), static_cast<float>(enemy.GetWidth()), static_cast<float>(enemy.GetHeight()))) {
                    proj.SetActive(false);
                    enemy.Respawn();
                    // 敵を倒したカウントを増やす
                    gEnemyKillCount++;
                }
            }
        }
    }
}
