#include "EnemyShip.h"
#include <Novice.h>
#include <cstdlib>

namespace Game {

EnemyShip::EnemyShip()
    : x_(0)
    , y_(0)
    , speed_(2.0f)
    , width_(32)
    , height_(32)
    , active_(true)
{
}

void EnemyShip::Initialize()
{
    // 右端からランダムなY座標で出現
    x_ = 1280.0f;
    y_ = static_cast<float>(rand() % (720 - height_));
    active_ = true;
}

void EnemyShip::Update()
{
    x_ -= speed_;
    if (x_ + width_ < 0) {
        active_ = false;
    }
}

void EnemyShip::Draw() const
{
    if (active_) {
        // 敵を赤いボックスで描画
        Novice::DrawBox(static_cast<int>(x_), static_cast<int>(y_), width_, height_, 0.0f, 0xFF0000FF, kFillModeSolid);
    }
}

bool EnemyShip::IsActive() const { return active_; }

void EnemyShip::Respawn()
{
    x_ = 1280.0f;
    y_ = static_cast<float>(rand() % (720 - height_));
    active_ = true;
}

float EnemyShip::GetX() const { return x_; }
float EnemyShip::GetY() const { return y_; }
int EnemyShip::GetWidth() const { return width_; }
int EnemyShip::GetHeight() const { return height_; }

}