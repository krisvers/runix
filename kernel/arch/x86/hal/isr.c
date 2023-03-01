#include <arch/x86/hal/isr.h>

ISRHandler isr_handlers[256];

static const char * const exceptions[] = {
	"Divide by zero exception",
	"Debug",
	"Non-maskable interrupt",
	"Breakpoint",
	"Overflow",
	"Bound Range Exceeded",
	"Invalid Opcode",
	"Device Not Available",
	"Double Fault",
	"Coprocessor Segment Overrun",
	"Invalid TSS",
	"Segment Not Present",
	"Stack Segment Fault",
	"General Protection Fault",
	"Page Fault",
	"",
	"x87 Floating-Point Exception",
	"Alignment Check",
	"Machine Check",
	"SIMD Floating-Point Exception",
	"Virtualization Exception",
	"Control Protection Exception",
	"",
	"",
	"",
	"",
	"",
	"",
	"Hypervisor Injection Exception",
	"VMM Communication Exception",
	"Security Exception",
	""
};

void __attribute((cdecl)) ISR0();
void __attribute((cdecl)) ISR1();
void __attribute((cdecl)) ISR2();
void __attribute((cdecl)) ISR3();
void __attribute((cdecl)) ISR4();
void __attribute((cdecl)) ISR5();
void __attribute((cdecl)) ISR6();
void __attribute((cdecl)) ISR7();
void __attribute((cdecl)) ISR8();
void __attribute((cdecl)) ISR9();
void __attribute((cdecl)) ISR10();
void __attribute((cdecl)) ISR11();
void __attribute((cdecl)) ISR12();
void __attribute((cdecl)) ISR13();
void __attribute((cdecl)) ISR14();
void __attribute((cdecl)) ISR15();
void __attribute((cdecl)) ISR16();
void __attribute((cdecl)) ISR17();
void __attribute((cdecl)) ISR18();
void __attribute((cdecl)) ISR19();
void __attribute((cdecl)) ISR20();
void __attribute((cdecl)) ISR21();
void __attribute((cdecl)) ISR22();
void __attribute((cdecl)) ISR23();
void __attribute((cdecl)) ISR24();
void __attribute((cdecl)) ISR25();
void __attribute((cdecl)) ISR26();
void __attribute((cdecl)) ISR27();
void __attribute((cdecl)) ISR28();
void __attribute((cdecl)) ISR29();
void __attribute((cdecl)) ISR30();
void __attribute((cdecl)) ISR31();
void __attribute((cdecl)) ISR32();
void __attribute((cdecl)) ISR33();
void __attribute((cdecl)) ISR34();
void __attribute((cdecl)) ISR35();
void __attribute((cdecl)) ISR36();
void __attribute((cdecl)) ISR37();
void __attribute((cdecl)) ISR38();
void __attribute((cdecl)) ISR39();
void __attribute((cdecl)) ISR40();
void __attribute((cdecl)) ISR41();
void __attribute((cdecl)) ISR42();
void __attribute((cdecl)) ISR43();
void __attribute((cdecl)) ISR44();
void __attribute((cdecl)) ISR45();
void __attribute((cdecl)) ISR46();
void __attribute((cdecl)) ISR47();
void __attribute((cdecl)) ISR48();
void __attribute((cdecl)) ISR49();
void __attribute((cdecl)) ISR50();
void __attribute((cdecl)) ISR51();
void __attribute((cdecl)) ISR52();
void __attribute((cdecl)) ISR53();
void __attribute((cdecl)) ISR54();
void __attribute((cdecl)) ISR55();
void __attribute((cdecl)) ISR56();
void __attribute((cdecl)) ISR57();
void __attribute((cdecl)) ISR58();
void __attribute((cdecl)) ISR59();
void __attribute((cdecl)) ISR60();
void __attribute((cdecl)) ISR61();
void __attribute((cdecl)) ISR62();
void __attribute((cdecl)) ISR63();
void __attribute((cdecl)) ISR64();
void __attribute((cdecl)) ISR65();
void __attribute((cdecl)) ISR66();
void __attribute((cdecl)) ISR67();
void __attribute((cdecl)) ISR68();
void __attribute((cdecl)) ISR69();
void __attribute((cdecl)) ISR70();
void __attribute((cdecl)) ISR71();
void __attribute((cdecl)) ISR72();
void __attribute((cdecl)) ISR73();
void __attribute((cdecl)) ISR74();
void __attribute((cdecl)) ISR75();
void __attribute((cdecl)) ISR76();
void __attribute((cdecl)) ISR77();
void __attribute((cdecl)) ISR78();
void __attribute((cdecl)) ISR79();
void __attribute((cdecl)) ISR80();
void __attribute((cdecl)) ISR81();
void __attribute((cdecl)) ISR82();
void __attribute((cdecl)) ISR83();
void __attribute((cdecl)) ISR84();
void __attribute((cdecl)) ISR85();
void __attribute((cdecl)) ISR86();
void __attribute((cdecl)) ISR87();
void __attribute((cdecl)) ISR88();
void __attribute((cdecl)) ISR89();
void __attribute((cdecl)) ISR90();
void __attribute((cdecl)) ISR91();
void __attribute((cdecl)) ISR92();
void __attribute((cdecl)) ISR93();
void __attribute((cdecl)) ISR94();
void __attribute((cdecl)) ISR95();
void __attribute((cdecl)) ISR96();
void __attribute((cdecl)) ISR97();
void __attribute((cdecl)) ISR98();
void __attribute((cdecl)) ISR99();
void __attribute((cdecl)) ISR100();
void __attribute((cdecl)) ISR101();
void __attribute((cdecl)) ISR102();
void __attribute((cdecl)) ISR103();
void __attribute((cdecl)) ISR104();
void __attribute((cdecl)) ISR105();
void __attribute((cdecl)) ISR106();
void __attribute((cdecl)) ISR107();
void __attribute((cdecl)) ISR108();
void __attribute((cdecl)) ISR109();
void __attribute((cdecl)) ISR110();
void __attribute((cdecl)) ISR111();
void __attribute((cdecl)) ISR112();
void __attribute((cdecl)) ISR113();
void __attribute((cdecl)) ISR114();
void __attribute((cdecl)) ISR115();
void __attribute((cdecl)) ISR116();
void __attribute((cdecl)) ISR117();
void __attribute((cdecl)) ISR118();
void __attribute((cdecl)) ISR119();
void __attribute((cdecl)) ISR120();
void __attribute((cdecl)) ISR121();
void __attribute((cdecl)) ISR122();
void __attribute((cdecl)) ISR123();
void __attribute((cdecl)) ISR124();
void __attribute((cdecl)) ISR125();
void __attribute((cdecl)) ISR126();
void __attribute((cdecl)) ISR127();
void __attribute((cdecl)) ISR128();
void __attribute((cdecl)) ISR129();
void __attribute((cdecl)) ISR130();
void __attribute((cdecl)) ISR131();
void __attribute((cdecl)) ISR132();
void __attribute((cdecl)) ISR133();
void __attribute((cdecl)) ISR134();
void __attribute((cdecl)) ISR135();
void __attribute((cdecl)) ISR136();
void __attribute((cdecl)) ISR137();
void __attribute((cdecl)) ISR138();
void __attribute((cdecl)) ISR139();
void __attribute((cdecl)) ISR140();
void __attribute((cdecl)) ISR141();
void __attribute((cdecl)) ISR142();
void __attribute((cdecl)) ISR143();
void __attribute((cdecl)) ISR144();
void __attribute((cdecl)) ISR145();
void __attribute((cdecl)) ISR146();
void __attribute((cdecl)) ISR147();
void __attribute((cdecl)) ISR148();
void __attribute((cdecl)) ISR149();
void __attribute((cdecl)) ISR150();
void __attribute((cdecl)) ISR151();
void __attribute((cdecl)) ISR152();
void __attribute((cdecl)) ISR153();
void __attribute((cdecl)) ISR154();
void __attribute((cdecl)) ISR155();
void __attribute((cdecl)) ISR156();
void __attribute((cdecl)) ISR157();
void __attribute((cdecl)) ISR158();
void __attribute((cdecl)) ISR159();
void __attribute((cdecl)) ISR160();
void __attribute((cdecl)) ISR161();
void __attribute((cdecl)) ISR162();
void __attribute((cdecl)) ISR163();
void __attribute((cdecl)) ISR164();
void __attribute((cdecl)) ISR165();
void __attribute((cdecl)) ISR166();
void __attribute((cdecl)) ISR167();
void __attribute((cdecl)) ISR168();
void __attribute((cdecl)) ISR169();
void __attribute((cdecl)) ISR170();
void __attribute((cdecl)) ISR171();
void __attribute((cdecl)) ISR172();
void __attribute((cdecl)) ISR173();
void __attribute((cdecl)) ISR174();
void __attribute((cdecl)) ISR175();
void __attribute((cdecl)) ISR176();
void __attribute((cdecl)) ISR177();
void __attribute((cdecl)) ISR178();
void __attribute((cdecl)) ISR179();
void __attribute((cdecl)) ISR180();
void __attribute((cdecl)) ISR181();
void __attribute((cdecl)) ISR182();
void __attribute((cdecl)) ISR183();
void __attribute((cdecl)) ISR184();
void __attribute((cdecl)) ISR185();
void __attribute((cdecl)) ISR186();
void __attribute((cdecl)) ISR187();
void __attribute((cdecl)) ISR188();
void __attribute((cdecl)) ISR189();
void __attribute((cdecl)) ISR190();
void __attribute((cdecl)) ISR191();
void __attribute((cdecl)) ISR192();
void __attribute((cdecl)) ISR193();
void __attribute((cdecl)) ISR194();
void __attribute((cdecl)) ISR195();
void __attribute((cdecl)) ISR196();
void __attribute((cdecl)) ISR197();
void __attribute((cdecl)) ISR198();
void __attribute((cdecl)) ISR199();
void __attribute((cdecl)) ISR200();
void __attribute((cdecl)) ISR201();
void __attribute((cdecl)) ISR202();
void __attribute((cdecl)) ISR203();
void __attribute((cdecl)) ISR204();
void __attribute((cdecl)) ISR205();
void __attribute((cdecl)) ISR206();
void __attribute((cdecl)) ISR207();
void __attribute((cdecl)) ISR208();
void __attribute((cdecl)) ISR209();
void __attribute((cdecl)) ISR210();
void __attribute((cdecl)) ISR211();
void __attribute((cdecl)) ISR212();
void __attribute((cdecl)) ISR213();
void __attribute((cdecl)) ISR214();
void __attribute((cdecl)) ISR215();
void __attribute((cdecl)) ISR216();
void __attribute((cdecl)) ISR217();
void __attribute((cdecl)) ISR218();
void __attribute((cdecl)) ISR219();
void __attribute((cdecl)) ISR220();
void __attribute((cdecl)) ISR221();
void __attribute((cdecl)) ISR222();
void __attribute((cdecl)) ISR223();
void __attribute((cdecl)) ISR224();
void __attribute((cdecl)) ISR225();
void __attribute((cdecl)) ISR226();
void __attribute((cdecl)) ISR227();
void __attribute((cdecl)) ISR228();
void __attribute((cdecl)) ISR229();
void __attribute((cdecl)) ISR230();
void __attribute((cdecl)) ISR231();
void __attribute((cdecl)) ISR232();
void __attribute((cdecl)) ISR233();
void __attribute((cdecl)) ISR234();
void __attribute((cdecl)) ISR235();
void __attribute((cdecl)) ISR236();
void __attribute((cdecl)) ISR237();
void __attribute((cdecl)) ISR238();
void __attribute((cdecl)) ISR239();
void __attribute((cdecl)) ISR240();
void __attribute((cdecl)) ISR241();
void __attribute((cdecl)) ISR242();
void __attribute((cdecl)) ISR243();
void __attribute((cdecl)) ISR244();
void __attribute((cdecl)) ISR245();
void __attribute((cdecl)) ISR246();
void __attribute((cdecl)) ISR247();
void __attribute((cdecl)) ISR248();
void __attribute((cdecl)) ISR249();
void __attribute((cdecl)) ISR250();
void __attribute((cdecl)) ISR251();
void __attribute((cdecl)) ISR252();
void __attribute((cdecl)) ISR253();
void __attribute((cdecl)) ISR254();
void __attribute((cdecl)) ISR255();

void isr_initgates() {
	idt_setgate(0, ISR0, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(1, ISR1, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(2, ISR2, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(3, ISR3, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(4, ISR4, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(5, ISR5, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(6, ISR6, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(7, ISR7, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(8, ISR8, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(9, ISR9, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(10, ISR10, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(11, ISR11, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(12, ISR12, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(13, ISR13, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(14, ISR14, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(15, ISR15, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(16, ISR16, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(17, ISR17, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(18, ISR18, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(19, ISR19, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(20, ISR20, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(21, ISR21, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(22, ISR22, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(23, ISR23, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(24, ISR24, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(25, ISR25, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(26, ISR26, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(27, ISR27, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(28, ISR28, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(29, ISR29, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(30, ISR30, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(31, ISR31, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(32, ISR32, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(33, ISR33, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(34, ISR34, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(35, ISR35, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(36, ISR36, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(37, ISR37, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(38, ISR38, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(39, ISR39, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(40, ISR40, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(41, ISR41, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(42, ISR42, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(43, ISR43, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(44, ISR44, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(45, ISR45, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(46, ISR46, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(47, ISR47, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(48, ISR48, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(49, ISR49, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(50, ISR50, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(51, ISR51, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(52, ISR52, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(53, ISR53, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(54, ISR54, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(55, ISR55, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(56, ISR56, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(57, ISR57, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(58, ISR58, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(59, ISR59, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(60, ISR60, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(61, ISR61, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(62, ISR62, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(63, ISR63, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(64, ISR64, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(65, ISR65, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(66, ISR66, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(67, ISR67, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(68, ISR68, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(69, ISR69, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(70, ISR70, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(71, ISR71, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(72, ISR72, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(73, ISR73, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(74, ISR74, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(75, ISR75, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(76, ISR76, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(77, ISR77, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(78, ISR78, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(79, ISR79, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(80, ISR80, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(81, ISR81, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(82, ISR82, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(83, ISR83, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(84, ISR84, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(85, ISR85, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(86, ISR86, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(87, ISR87, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(88, ISR88, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(89, ISR89, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(90, ISR90, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(91, ISR91, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(92, ISR92, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(93, ISR93, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(94, ISR94, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(95, ISR95, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(96, ISR96, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(97, ISR97, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(98, ISR98, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(99, ISR99, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(100, ISR100, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(101, ISR101, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(102, ISR102, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(103, ISR103, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(104, ISR104, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(105, ISR105, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(106, ISR106, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(107, ISR107, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(108, ISR108, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(109, ISR109, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(110, ISR110, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(111, ISR111, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(112, ISR112, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(113, ISR113, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(114, ISR114, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(115, ISR115, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(116, ISR116, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(117, ISR117, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(118, ISR118, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(119, ISR119, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(120, ISR120, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(121, ISR121, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(122, ISR122, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(123, ISR123, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(124, ISR124, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(125, ISR125, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(126, ISR126, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(127, ISR127, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(128, ISR128, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(129, ISR129, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(130, ISR130, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(131, ISR131, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(132, ISR132, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(133, ISR133, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(134, ISR134, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(135, ISR135, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(136, ISR136, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(137, ISR137, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(138, ISR138, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(139, ISR139, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(140, ISR140, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(141, ISR141, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(142, ISR142, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(143, ISR143, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(144, ISR144, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(145, ISR145, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(146, ISR146, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(147, ISR147, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(148, ISR148, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(149, ISR149, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(150, ISR150, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(151, ISR151, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(152, ISR152, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(153, ISR153, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(154, ISR154, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(155, ISR155, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(156, ISR156, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(157, ISR157, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(158, ISR158, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(159, ISR159, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(160, ISR160, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(161, ISR161, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(162, ISR162, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(163, ISR163, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(164, ISR164, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(165, ISR165, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(166, ISR166, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(167, ISR167, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(168, ISR168, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(169, ISR169, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(170, ISR170, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(171, ISR171, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(172, ISR172, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(173, ISR173, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(174, ISR174, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(175, ISR175, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(176, ISR176, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(177, ISR177, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(178, ISR178, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(179, ISR179, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(180, ISR180, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(181, ISR181, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(182, ISR182, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(183, ISR183, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(184, ISR184, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(185, ISR185, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(186, ISR186, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(187, ISR187, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(188, ISR188, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(189, ISR189, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(190, ISR190, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(191, ISR191, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(192, ISR192, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(193, ISR193, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(194, ISR194, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(195, ISR195, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(196, ISR196, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(197, ISR197, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(198, ISR198, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(199, ISR199, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(200, ISR200, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(201, ISR201, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(202, ISR202, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(203, ISR203, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(204, ISR204, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(205, ISR205, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(206, ISR206, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(207, ISR207, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(208, ISR208, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(209, ISR209, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(210, ISR210, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(211, ISR211, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(212, ISR212, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(213, ISR213, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(214, ISR214, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(215, ISR215, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(216, ISR216, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(217, ISR217, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(218, ISR218, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(219, ISR219, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(220, ISR220, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(221, ISR221, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(222, ISR222, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(223, ISR223, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(224, ISR224, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(225, ISR225, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(226, ISR226, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(227, ISR227, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(228, ISR228, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(229, ISR229, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(230, ISR230, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(231, ISR231, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(232, ISR232, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(233, ISR233, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(234, ISR234, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(235, ISR235, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(236, ISR236, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(237, ISR237, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(238, ISR238, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(239, ISR239, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(240, ISR240, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(241, ISR241, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(242, ISR242, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(243, ISR243, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(244, ISR244, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(245, ISR245, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(246, ISR246, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(247, ISR247, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(248, ISR248, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(249, ISR249, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(250, ISR250, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(251, ISR251, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(252, ISR252, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(253, ISR253, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(254, ISR254, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
	idt_setgate(255, ISR255, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);

	for (int i = 0; i < 256; i++) {
		idt_enablegate(i);
	}
}
void isr_init() {
	isr_initgates();

    putcolor(LIGHT_GREY);
    printf("isr initialized [");
    putcolor(GREEN);
    printf("*");
    putcolor(LIGHT_GREY);
    printf("]\n");
}

void __attribute((cdecl)) isr_handler(Registers * regs) {
	if (isr_handlers[regs->interrupt] != NULL) {
		isr_handlers[regs->interrupt](regs);
	} else if (regs->interrupt >= 32) {
		printf("Unhandled interrupt %i\n", regs->interrupt);
	} else {
		printf("Unhandled exception %i: %s\n", regs->interrupt, exceptions[regs->interrupt]);
		printf("	eax=%x,	ebx=%x,	ecx=%x,	edx=%x,	esi=%x,	edi=%x\n",
				regs->eax,	regs->ebx,	regs->ecx,	regs->edx,	regs->esi,	regs->edi);
		printf("	esp=%x,	ebp=%x,	eip=%x,	cflags=%x\n	cs=%x,	ds=%x,	ss=%x\n",
				regs->esp,	regs->ebp,	regs->eip,	regs->cflags,	regs->cs,	regs->ds,	regs->ss);
		printf("	interrupt=%x,	errorcode=%x\n", regs->interrupt, regs->error);
		abort();
	}
}

void isr_reg_handler(int interrupt, ISRHandler handler) {
	isr_handlers[interrupt] = handler;
	idt_enablegate(interrupt);
}
