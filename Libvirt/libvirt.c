#include<stdio.h>
#include <stdlib.h>

struct Virtualmachine
{   /*Variabelen*/
	int number;
	char string[10];
	char osnaam[100];
	char imgpad[100];
	char isopad[100];
	char osnaam[20];
	char ramgrootte[10];
	double schijfgrootte[5];
	char gebruikersnaam[50];
	char uuid[50];
};

void createdata(FILE *fb, struct Virtualmachine virtuelemachinedata)
{
	fprintf(fb, <domain type = 'kvm'>
	fprintf(fb, <name>osnaam< / name>
	fprintf(fb, <uuid>%s,uuid< / uuid>
	fprintf(fb, < memory>%dramgrootte< / memory >
	fprintf(fb, < vcpu>1 < / vcpu >
	fprintf(fb, <os>
	fprintf(fb, <type>hvm< / type>
	fprintf(fb, <boot dev = 'cdrom' / >
	fprintf(fb, < / os>
	fprintf(fb, <features>
	fprintf(fb, <acpi / >
	fprintf(fb, < / features>
	fprintf(fb, <clock offset = 'utc' / >
	fprintf(fb, <on_poweroff>destroy< / on_poweroff>
	fprintf(fb, <on_reboot>restart< / on_reboot>
	fprintf(fb, <on_reboot>restart< / on_reboot>
	fprintf(fb, <emulator> / usr / bin / kvm< / emulator>
	fprintf(fb, <disk type = "file" device = "disk">
	fprintf(fb, <driver name = "qemu" type = "raw" / >
	fprintf(fb, <source file = imgpad / > /*.img*/
	fprintf(fb, <target dev = "vda" bus = "virtio" / >
	fprintf(fb, <address type = "pci" domain = "0x0000" bus = "0x00" slot = "0x04" function = "0x0" / >
	fprintf(fb, < / disk>
	fprintf(fb, <disk type = "file" device = "cdrom">
	fprintf(fb, <driver name = "qemu" type = "raw" / >
	fprintf(fb, <source file = isopad / >
	fprintf(fb, <target dev = "hdc" bus = "ide" / >
	fprintf(fb, <readonly / >
	fprintf(fb, <address type = "drive" controller = "0" bus = "1" target = "0" unit = "0" / >
	fprintf(fb, < / disk>
	fprintf(fb, <interface type = 'bridge'>
	fprintf(fb, <source bridge = 'br0' / >
	fprintf(fb, <mac address = "00:00:A3:B0:56:10" / >
	fprintf(fb, < / interface>
	fprintf(fb, <controller type = "ide" index = "0">
	fprintf(fb, <address type = "pci" domain = "0x0000" bus = "0x00" slot = "0x01" function = "0x1" / >
	fprintf(fb, < / controller>
	fprintf(fb, <input type = 'mouse' bus = 'usb' / >
	fprintf(fb, <graphics type = 'vnc' port = '-1' autoport = "yes" listen = '0.0.0.0' / >
	fprintf(fb, <graphics type = 'vnc' port = '-1' autoport = "yes" listen = '0.0.0.0' / >
	fprintf(fb, <console type = 'pty'>
	fprintf(fb, <target port = '0' / >
	fprintf(fb, < / console>
	fprintf(fb, < / devices>
	fprintf(fb, < / domain>
}

int main()
{
    	system("apt-get install qemu-kvm libvirt-bin");

	fprintf("Hoe wilt de virtuele machine noemen? \n");
		scanf("%s", &osnaam);

	fprintf("Op welk pad staat het imagebestand? \n");
		scanf("%s", &imgpad);

	fprintf("Op welk pad staat het isobestand? \n");
	scanf("%s", &isopad);

	fprintf("Hoeveel RAM moet de virtuele machine krijgen? \n");
	scanf("%s", &ramgrootte);

	fprintf("Hoeveel Gigabyte moet de hardeschijf zijn? \n");
	scanf("%d", &schijfgrootte);

	fprintf("Geef een geregistreerde gebruikersnaam op \n");
	scanf("%s", &gebruikersnaam);

	system("adduser %s", &gebruikersnaam);
	system("apt-get install bridge-utils");
	system("brctl addbr br0");
	system("systemctl stop NetworkManager.service");
	system("systemctl disable NetworkManager.service");
	system("apt-get install bridge-utils");
	system("brctl addbr br0");
	fprintf("Voer nano /etc/network/interfaces uit en plak de volgende tekst hierin: \n");
	fprintf("#auto eth0 \n	#iface eth0 inet dhcp\n auto br0\n	iface br0 inet dhcp\n");
	fprintf("bridge_ports eth0\n bridge_stp off\n bridge_fd 0\n	bridge_maxwait 0");
	system("/etc/init.d/networking restart");
	system("apt-get install uuid");
	system("uuid");
	/*hier moet een temp file komen om uuid te verwerken in een variabele, die ik dan kan gebruiken in het .xmlbestand. Ik weet niet zeker of ik dat zo in het .xmlbestand kan zetten. Is het makkelijker om dit in python te doen?*/
	system("qemu-img create -f qcow2 /home/dev/images/ %s", osnaam ,".img %d", schijfgrootte, "G");
	system("virsh create %s", osnaam, ".xml");
	system("virsh start %s", osnaam, ".xml");
	system("virsh autostart %s", osnaam);
}
