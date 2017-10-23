#include <stdint.h>

class Pin
{
    public:
        Pin(int nr, int dir, int pull_up);
        void set(int value);
        int get(void);
        void changeDir(void);

    private:
        int numar;
    private:
        int directie;
    private:
        int pullUp;
};
