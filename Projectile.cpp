#include "Projectile.h"
#include <Novice.h>

namespace Game {

Projectile::Projectile()
    : x_(0)
    , y_(0)
    , speed_(10.0f)
    , width_(8)
    , height_(8)
    , active_(false)
{
}

void Projectile::Initialize()
{
    active_ = true;
}

void Projectile::Update()
{
    if (active_) {
        x_ += speed_;
        if (x_ > 1280) {
            active_ = false;
        }
    }
}

void Projectile::Draw() const
{
    if (active_) {
        // 弾を黄色いボックスで描画
        Novice::DrawBox(static_cast<int>(x_), static_cast<int>(y_), width_, height_, 0.0f, 0xFFFF00FF, kFillModeSolid);
    }
}

bool Projectile::IsActive() const { return active_; }
void Projectile::SetActive(bool active) { active_ = active; }
void Projectile::SetPosition(float x, float y)
{
    x_ = x;
    y_ = y;
}
float Projectile::GetX() const { return x_; }
float Projectile::GetY() const { return y_; }
int Projectile::GetWidth() const { return width_; }
int Projectile::GetHeight() const { return height_; }

}
