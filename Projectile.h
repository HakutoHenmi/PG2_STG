#pragma once

namespace Game {

class Projectile {
public:
    Projectile();
    void Initialize();
    void Update();
    void Draw() const;
    bool IsActive() const;
    void SetActive(bool active);
    void SetPosition(float x, float y);
    float GetX() const;
    float GetY() const;
    int GetWidth() const;
    int GetHeight() const;

private:
    float x_;
    float y_;
    float speed_;
    int width_;
    int height_;
    bool active_;
};

}
