//
// Created by mwisniewski on 3/25/20.
//

#include <unistd.h>
#include "../headers/Visualizer.h"
#include "../headers/Parameters.h"

void Visualizer::init() {
    initscr();
    noecho();
    box(stdscr, 0, 0);
    use_default_colors();
    start_color();

    getmaxyx(stdscr, window_params.y_max, window_params.x_max);
    window_params.x_margin = 0.05 * (float) window_params.x_max;
    window_params.y_margin = 0.1 * (float) window_params.y_max;
    window_params.separator = (float) (window_params.x_max) * 0.55;

    int column_width = (float) (window_params.separator - window_params.x_margin) / 2;
    init_pair(9, COLOR_WHITE, -1);

    wattron(stdscr, COLOR_PAIR(9));

    mvwprintw(stdscr, window_params.y_margin / 2, window_params.x_max / 2 - 16, "THE DINING PHILOSOPHERS");
    mvwprintw(stdscr, window_params.y_max - window_params.y_margin / 2,
              window_params.x_max - window_params.x_margin - 22, "Mariusz Wisniewski 241393");

    wattroff(stdscr, COLOR_PAIR(9));

    refresh();

    window = derwin(stdscr, window_params.y_max - 2 * window_params.y_margin,
                    window_params.separator - window_params.x_margin, window_params.y_margin, window_params.x_margin);
    box(window, 0, 0);

    wprintw(window, "Philosophers");

    mvwprintw(window, 2, 2, "Id");
    mvwprintw(window, 2, column_width, "State");

    mvwhline(window, 4, 1, 0, window_params.separator - window_params.x_margin - 2);
    mvwvline(window, 1, column_width - 2, 0, window_params.y_max - 2 * window_params.y_margin - 2);

    touchwin(window);

    wrefresh(window);
}

void Visualizer::update_screen() {
    int column_width = (float) (window_params.separator - window_params.x_margin) / 2;
    char buf[2];
    const char *p;
    init_pair(1, COLOR_GREEN, -1);
    init_pair(2, COLOR_BLUE, -1);
    init_pair(3, COLOR_YELLOW, -1);
    init_pair(4, COLOR_CYAN, -1);

//    for (int i = 0; i < NUMBER_OF_PHILOSOPHERS; i++) {
//        sprintf(buf, "%d", philosophers[i]->get_id());
//        p = buf;
//        mvwprintw(window, 2 * i + 5, 3, "%s", p);
//
//        switch(philosophers[i]->get_state()) {
//            case State::EATING:
//                wattron(window, COLOR_PAIR(1));
//                mvwprintw(window, 2 * i + 5, column_width + 1, "eating  ");
//                wattroff(window, COLOR_PAIR(1));
//                break;
//
//            case State::THINKING:
//                wattron(window, COLOR_PAIR(2));
//                mvwprintw(window, 2 * i + 5, column_width + 1, "thinking");
//                wattroff(window, COLOR_PAIR(2));
//                break;
//
//            case State::WAITING_FOR_FORKS:
//                wattron(window, COLOR_PAIR(3));
//                mvwprintw(window, 2 * i + 5, column_width + 1, "waiting ");
//                wattroff(window, COLOR_PAIR(3));
//                break;
//
//            default:
//                wattron(window, COLOR_PAIR(4));
//                mvwprintw(window, 2 * i + 5, column_width + 1, "sleeping");
//                wattroff(window, COLOR_PAIR(4));
//                break;
//        }
//    }
//    touchwin(window);
//    wrefresh(window);
}


void Visualizer::update() {
    while (table.no_of_ready_philosophers) {
        update_screen();
    }
}

Visualizer::~Visualizer() {
    delwin(window);
    endwin();

    philosophers.clear();
    thread.join();
}

Visualizer::Visualizer(std::vector<std::shared_ptr<Philosopher> > &philosophers, Table &table) : philosophers(
        philosophers), table(table), thread(&Visualizer::update, this) {
    init();
}
