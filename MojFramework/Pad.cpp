#include "Pad.h"

Pad::Pad(Vei2 pos_in)
    :
    pos(pos_in),
    pos_temp(pos)
{}

void Pad::Draw(Graphics& gfx) const
{
    gfx.DrawRect(RectI(pos, width, height), color);
}

bool Pad::DoBallCollision(Ball& ball) const
{
    if (ball.GetVelocity().y > 0.0f && GetRect().IsOverlappingWith(ball.GetRect()))
    {
        ball.ReboundY();
        return true;
    }
    return false;
}

void Pad::DoWallCollision(const RectI& walls)
{
    const RectI rect = GetRect();
    if (rect.left < walls.left)
    {
        pos_temp.x = 1;
    }
    else if (rect.right >= walls.right)
    {
        pos_temp.x = float(Graphics::ScreenWidth - width - 1);
    }
    pos = pos_temp;
}

void Pad::Update(const Keyboard& kbd, float dt)
{
    float baseSpeed = 300.0f;
    float speed = baseSpeed * dt;

    if (kbd.KeyIsPressed(VK_SPACE))
        speed *= 2.0f;

    if (kbd.KeyIsPressed('A')) pos_temp.x -= speed;
    if (kbd.KeyIsPressed('D')) pos_temp.x += speed;
    pos = pos_temp;
}

RectI Pad::GetRect() const
{
    return RectI(pos, width, height);
}