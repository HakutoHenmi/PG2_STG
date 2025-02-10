#pragma once
#include "EnemyShip.h"
#include "IGameScene.h"
#include "PlayerShip.h"
#include "Projectile.h"
#include <vector>

// 倒した敵の数を管理
extern int gEnemyKillCount;

class GamePlayScene : public IGameScene {
public:
    GamePlayScene();
    virtual ~GamePlayScene();

    virtual void Initialize() override;
    virtual void Update(const char* keys, const char* preKeys) override;
    virtual void Draw() override;
    virtual void Finalize() override;
    virtual int GetNextScene() const override;

private:
    int nextScene_;
    Game::PlayerShip playerShip_;
    std::vector<Game::EnemyShip> enemies_;
    std::vector<Game::Projectile> projectiles_;

    void CheckCollisions();
    bool CheckCollisionRect(float x1, float y1, float w1, float h1,
        float x2, float y2, float w2, float h2);
};
