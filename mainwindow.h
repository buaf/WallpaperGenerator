#ifndef MAINWINDOW_H
#define MAINWINDOW_H

class MainWindow
{
public:
    MainWindow();
    ~MainWindow();

    static int desctopWidth, desctopHeight;

private:
    void updateImage();
    void deleteOldImages();
};

#endif // MAINWINDOW_H
