#include <SDL3/SDL.h>
#include <iostream>

int main(int argc, char* argv[]) {
    // 1. SDLの初期化 (ビデオ機能)
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("SDL_Init Error: %s", SDL_GetError());
        return 1;
    }

    // 2. ウィンドウの作成
    // SDL3では第4引数にフラグを指定します（0はデフォルト）
    SDL_Window* window = SDL_CreateWindow("CPP STG - SDL3", 800, 600, 0);
    if (window == nullptr) {
        SDL_Log("SDL_CreateWindow() Error: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // 3. レンダラーの作成
    // 第2引数にNULLを指定すると、最適なドライバーを自動選択します
    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);
    if (renderer == nullptr) {
        SDL_Log("SDL_CreateRenderer() Error: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // 4. メインループ
    bool running = true; // SDL3では標準のboolを使います
    SDL_Event event;

    while (running) {
        // イベント処理
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) { // SDL2のSDL_QUITから名称変更
                running = false;
            }
        }

        // 描画処理 (背景を黒で塗りつぶし)
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // --- ここでゲームオブジェクトの描画などを行う ---

        // 画面を更新
        SDL_RenderPresent(renderer);
    }

    // 5. 後片付け
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}