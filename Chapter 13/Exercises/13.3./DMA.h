#ifndef DMA_H_
#define DMA_H_

//Абстрактный базовый класс

class DMA
{
    private:
        char * label;
    public:
        DMA(const char * l = "null");
        DMA(const DMA & rs);
        virtual ~DMA();
        DMA & operator=(const DMA & rs);
        virtual void View() const = 0;
};


//Производный класс baseDMA
class baseDMA : public DMA
{
    private:
        int rating;
    public:
        baseDMA(const char * l = "null", int r = 0);
        baseDMA(const baseDMA & rs, int r = 0);
        ~baseDMA() {}
        baseDMA & operator=(const baseDMA & rs);
        virtual void View() const;
};

//производный класс lacksDMA
//без динамического выделения памяти
//деструктор не нужен
class lacksDMA : public DMA
{
    private:
        enum{COL_LEN = 40};
        char color[COL_LEN];
    public:
        lacksDMA(const char * l = "null", const char * c = "blank");
        virtual void View() const;
};


//производный класс hasDMA
class hasDMA : public DMA
{
    private:
        char * style;
    public:
        hasDMA(const char * l = "null", const char * s = "null");
        hasDMA(const hasDMA & rs, const char * s = "null");
        ~hasDMA();
        hasDMA & operator=(const hasDMA & rs);
        virtual void View() const;
};
#endif
