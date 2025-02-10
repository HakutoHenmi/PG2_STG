#pragma once
#include "IGameScene.h"

class GameResultScene : public IGameScene {
public:
    GameResultScene();
    virtual ~GameResultScene();

    virtual void Initialize() override;
    virtual void Update(const char* keys, const char* preKeys) override;
    virtual void Draw() override;
    virtual void Finalize() override;
    virtual int GetNextScene() const override;

private:
    int nextScene_;
};
