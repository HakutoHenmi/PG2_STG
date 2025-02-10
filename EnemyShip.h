#pragma once

namespace Game {

class EnemyShip {
public:
    EnemyShip();
    void Initialize();
    void Update();
    void Draw() const;
    bool IsActive() const;
    void Respawn();
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