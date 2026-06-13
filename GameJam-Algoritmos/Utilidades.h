#pragma once

constexpr int TIEMPO_SLEEP = 75;
constexpr float CONVERSOR_SEG = TIEMPO_SLEEP * 1.0 / 1000;
constexpr float CONVERSOR_CONT = 1000 / TIEMPO_SLEEP * 1.0;

inline bool verificarColisiones(Entidad^ a, Entidad^ b) {
    if (a->getBounds().IntersectsWith(b->getBounds())) return true;
    return false;
}