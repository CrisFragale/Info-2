
#define DECISION 0
#define RIEGO 1

#define PESOS 0
#define DATOS 1
#define CORROBORO 2

#define CC 0
#define TOMODATOS 1
#define CARGADATOS 2

#define ON 1
#define OFF 0

#define PP 0
#define PASOINFO 1

#define VALVULA1 0,27
#define VALVULA2 0,21
#define VALVULA3 0,23
#define VALVULA4 2,0

typedef struct Mde{

	uint8_t Sector;
	uint8_t HumedadCriticaMAX;
	uint8_t HumedadCriticaMIN;
	uint8_t TiempoDeRiego;
	uint8_t HRiego[24];
	uint8_t DRiego[7];
	uint8_t Humedad;
	uint8_t Regado[24];
	uint8_t Habilitado;

}Mde_t;

typedef struct Rtc{

	uint8_t hora;
	uint8_t dia;
	uint8_t minutos;
}Rtc_t;


void SENSOR_init(void);
void ElectroValvula(uint8_t, uint8_t);
void MDE(Mde_t MDE);
void InicializarPLL(void);
void UART_Init(uint32_t);
void RTC_Init(void);
void SENSOR_init(void);
void InitADC(void);
void RTCconfig(void);
void InicializarSysTick(void);
void maquinapuertoserie(void);
void pasarinfo(void);

