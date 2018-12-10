#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	/*Controleren of de regels die worden ingevoerd kloppen*/
	if (!iptc_append_entry(chain, (struct ipt_entry *) &entry, h))
	{
		fprintf(stderr, "Deze regel kan niet aan Iptables worden toegevoegd (table %s): %s\n", table, iptc_strerror(errno));
		goto out;
	}
	/*if statement om te kijken of de veranderingen die in Iptables zijn aangebracht doorgezet kunnen worden*/
	if (!iptc_commit(h))
	{
		fprintf(stderr, "De veranderingen in iptables kunnen niet worden toegepast (table %s): %s\n", table, iptc_strerror(errno));
		goto out;
	}
	system("sudo sh firewall.sh");
	/*laat de lijst van de huidige iptables zien*/
	system("iptables -L");
	/*Google.com whitelisten*/
	system("if_lan="eth0"");
	system("addr_if_lan="8.8.8.8"");
	system("addr_whitelist="google.com"");
	system("net_lan="8.8.8.0 / 1"");

	/*Het toelaten van ssh-verbindingen met een maximum van 10 per minuut vanaf hetzelfde IP-adres)*/
	system("A INPUT - p tcp --dport 22 - m recent --rcheck --seconds 60 --hitcount 10 --name SSH - j LOG --log - prefix "SH "");
	system("A INPUT - p tcp --dport 22 - m recent --update --seconds 60 --hitcount 10 --name SSH - j DROP");
	system("A INPUT - p tcp --dport 22 - m state --state NEW - m recent --set --name SSH - j ACCEPT");
		
	/*SSH-connecties worden gewhitelist, er wordt geprobeerd bruteforce attacks te voorkomen*/
	system("N BRUTECHECK");
	system("A BRUTECHECK - m set --match - set bruteforce src - j DROP");
	system("A BRUTECHECK - j ACCEPT");
	system("N SSHSCAN");
	system("N SSHREJECT");
	system("A INPUT - i $if_lan - p TCP - d $addr_if_lan --dport 22 \- m state --state NEW - j SSHSCAN");
	system("A SSHSCAN - m set --match - set whitelist src - j ACCEPT");
	system("A SSHSCAN - m recent --set --name SSH");
	system("A SSHSCAN - m recent --update --hitcount 6 --seconds 600 \	--name SSH - j SSHREJECT");
	system("A SSHSCAN - j BRUTECHECK");
	system("A SSHREJECT - j SET --add - set bruteforce src");
	system("A SSHREJECT - j LOG --log - level info \--log - prefix "SSH bruteforce detected: "");
	system("A SSHREJECT - j DROP");

	/*accept everything from loopback*/
	system("A INPUT - i lo - j ACCEPT");
	system("A OUTPUT - o lo - j ACCEPT");

		# Het toelaten staan van ICMP-pakketten
		system("A INPUT - i $int_if - d $int_ip - p icmp - j ACCEPT");
		/*Het blokkeren van poorten waar vanaf vaak virussen verstuurd worden*/
		system("A INPUT - i $int_if - m multiport - p tcp --dports 53, 113, 135, 137, 139, 445 - j DROP");
		system("A INPUT - i $int_if - m multiport - p udp --dports 53, 113, 135, 137, 139, 445 - j DROP");
		system("A INPUT - i $int_if - p udp --dport 1026 - j DROP");
		system("A INPUT - i $int_if - m multiport - p tcp --dports 1433, 4899 - j DROP");
		system("A INPUT - p icmp - m limit --limit 10 / second - j ACCEPT");
		system("A INPUT - p icmp - j DROP");
		system("A INPUT - j LOG --log - prefix "IN "");
		system("A INPUT - j REJECT --reject - with icmp - port - unreachable");
		system("A OUTPUT - j LOG --log - prefix "OU "");
		system("A OUTPUT - j REJECT --reject - with icmp - port - unreachable");
		system("A FORWARD - j LOG --log - prefix "FW "");
		system("A FORWARD - j REJECT --reject - with icmp - port - unreachable");

		/*Het opslaan van de wijzigingen in de iptables*/
		system("/etc/init.d/iptables save");
		/*Iptables wordt opnieuw gestart*/
		system("/etc/init.d/iptables restart");
}