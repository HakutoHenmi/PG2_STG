#pragma once

namespace Game {

class PlayerShip {
public:
    PlayerShip();
    void Initialize();
    void Update(const char* keys, const char* preKeys);
    void Draw();
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
};

} 
