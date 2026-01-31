# P2ASW

**Part of the P2Mobile Project**

Portal 2 in Alien Swarm Engine (Fork)

This repository is a component of the Portal 2 Mobile Porting Project.

[Back to Main Project](https://github.com/F1xTrack/P2Android)

---

# P2ASW (Portal 2 Alien Swarm SDK Port)

## Роль в проекте: "Донор Логики"
Эта директория содержит исходный код игровой логики Portal 2, адаптированный из Alien Swarm SDK. Она не является самостоятельным движком для этого проекта, а служит библиотекой исходных кодов.

## Связь с корнем (`G:\_Projects\Portal2Mobile\`)
*   **Источник правды**: Файлы в `src/game/client`, `src/game/server` и `src/game/shared` являются эталоном поведения сущностей Portal 2 (кубы, кнопки, лазеры, порталы).
*   **Миграция**: Скрипты сборки и ручные переносы копируют код отсюда в `../source-engine/game/` (для Android) и `../sourcevr/game/` (для VR).
*   **VPC Файлы**: Файлы конфигурации проекта (`.vpc`) здесь используются парсерами в других директориях для понимания структуры проекта.

## Важные подпапки
*   `src/game/server/portal2`: Весь серверный код (поведение NPC, физика пазлов).
*   `src/game/client/portal2`: Клиентский код (C_BaseEntity, предсказание, HUD).
