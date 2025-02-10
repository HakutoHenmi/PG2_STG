#pragma once
class IGameScene {
public:
    virtual ~IGameScene() { }
    virtual void Initialize() = 0;
    virtual void Update(const char* keys, const char* preKeys) = 0;
    virtual void Draw() = 0;
    virtual void Finalize() = 0;
    // -1 を返す
    virtual int GetNextScene() const = 0;
};