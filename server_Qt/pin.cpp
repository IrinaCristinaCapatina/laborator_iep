Pin::Pin(int nr, bool dir, bool pull_up)
{
    this->numar = nr;
    this->directie = dir;
    this->pullUp = pull_up;
}


void Pin::set(void)
{

}

int Pin::get(void)
{

}

void Pin::changeDir(void)
{
    directie = ~directie;
}
