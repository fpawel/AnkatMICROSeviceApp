#ifndef MY_PERFORM_MODBUS_TRANSFER_HEADER_INCLUDED__________
#define MY_PERFORM_MODBUS_TRANSFER_HEADER_INCLUDED__________

#include "..\my_include\free_types_.h"

/**
*		Данная функция выполняет трансфер приёмопередачи.
*		Определяется в файле "hromat_sys.h".
*		Занимает 100% процессорных ресурсов.
*/
unsigned PerformModbusTransfer
(
	uInt8 slave,
	uInt8 commandCode,			// код комманды
	ByteBuffPtr sendBegin,		// ссылка на передаваемые данные
    ByteBuffPtr sendEnd,
    ByteBuffPtr& reciveBegin,
    ByteBuffPtr& reciveEnd
);

void SleepSyncronizedTransferPerforming(unsigned);

#endif
