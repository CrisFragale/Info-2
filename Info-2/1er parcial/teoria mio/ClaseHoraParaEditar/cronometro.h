#ifndef CRONOMETRO_H
#define CRONOMETRO_H


class cronometro
{
        private:
                int ms;

        public:

                cronometro(int h,int m ,int s, int _ms);
                cronometro(const &C);
                cronometro operator+=(int _ms);
                friend ostream& operator << (ostream& o,const cronometro&C);
};

#endif // CRONOMETRO_H
