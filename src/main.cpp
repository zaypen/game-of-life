#include <unistd.h>
#include "Game.h"

int main(int argc, char **argv) {
    uint32_t w = 40, h = 30;
    int c;
    while ((c = getopt(argc, argv, "w:h:")) != -1) {
        switch (c) {
            case 'w':
                w = static_cast<uint32_t>(atoi(optarg));
                break;
            case 'h':
                h = static_cast<uint32_t>(atoi(optarg));
                break;
            case '*':
            default:
                printf("Usage: %s [-w width] [-h height]\n", argv[0]);
                break;
        }
    }
    Game game(w, h);
    game.Run();
    return 0;
}
