#ifndef  SPI_INTERFACE
#define  SPI_INTERFACE


// Choose Master or Slave
void SPI_voidInialize(u8 Copy_u8ProtocaloType);

//To send and Receive Data
u8 SPI_u8Transceiver(u8 Copy_u8Data);

#endif