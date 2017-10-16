#include <stdint.h>

class Pin
{
    public:
        Pin(int nr, bool dir, bool pull_up);
        void set(void);
        int get(void);
        void changeDir(void);

    private:
        int numar;
    private:
        bool directie;
    private:
        bool pull_up;
};
