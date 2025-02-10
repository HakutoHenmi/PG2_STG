#include "PlayerShip.h"
#include <Novice.h>
#include <algorithm>
#include <cmath>

namespace Game {

PlayerShip::PlayerShip()
    : x_(100.0f)
    , y_(360.0f)
    , speed_(5.0f)
    , width_(32)
    , height_(32)
{
}

void PlayerShip::Initialize()
{
    x_ = 100.0f;
    y_ = 360.0f;
}

void PlayerShip::Update(const char* keys, const char* preKeys)
{
    // キャスト
    (void)preKeys;

    // キー入力により移動処理
    if (keys[DIK_A]) {
        x_ -= speed_;
    }
    if (keys[DIK_D]) {
        x_ += speed_;
    }
    if (keys[DIK_W]) {
        y_ -= speed_;
    }
    if (keys[DIK_S]) {
        y_ += speed_;
    }

    // 画面外処理
    x_ = (x_ < 0.0f ? 0.0f : (x_ > (1280.0f - static_cast<float>(width_)) ? (1280.0f - static_cast<float>(width_)) : x_));
    y_ = (y_ < 0.0f ? 0.0f : (y_ > (720.0f - static_cast<float>(height_)) ? (720.0f - static_cast<float>(height_)) : y_));
}

void PlayerShip::Draw()
{
    // 自機を白いボックスで描画
    Novice::DrawBox(static_cast<int>(x_), static_cast<int>(y_), width_, height_, 0.0f, 0xFFFFFFFF, kFillModeSolid);
}

float PlayerShip::GetX() const { return x_; }
float PlayerShip::GetY() const { return y_; }
int PlayerShip::GetWidth() const { return width_; }
int PlayerShip::GetHeight() const { return height_; }

}
