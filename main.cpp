#include "mainwindow.h"

#include <QApplication>
#include <sentry.h>

int main(int argc, char *argv[])
{
    sentry_options_t *options = sentry_options_new();
    sentry_options_set_debug(options, 1);
    sentry_options_set_dsn(options, "<your dsn url>");
    sentry_options_set_handler_path(options, "<path to your crashpad_handler>");
    sentry_options_set_database_path(options, "<path to an application config dir, ideally outside the bundle>");
    sentry_init(options);
    auto sentryClose = qScopeGuard([] { sentry_close(); });

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
