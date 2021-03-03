//PLEASE DO NOT USE THIS FILE before veryfing.

class CTrameKNX {
    private:
        unsigned char m_TrameEnTableau();
        unsigned char m_nombreOctetsMax();
        unsigned char m_octetControle();
        unsigned short int m_adresseDestinataire();
        unsigned char m_octet_SiAdresseGroupe_CompteurRoutage_longueurData();
        unsigned char m_nombreOctetsData();
        unsigned char m_octetSecurite();
        unsigned char m_emissionNormaleOuRepetition();
        unsigned char m_priorite();
    public:
        //CTrameKNX()
        //CTrameKNX() char *trameBruteKNX
        //~CTrameKNX()
        void seeTrameEnTableau(unsigned char trameEnTableau[6]);
        unsigned char getOctetControle();
        unsigned short int getAdresseSource();
        unsigned short int getAdresseDestinataire();
        unsigned char getOctet_SiAdresseGroupe_CompteurRoutage_LongueurData();
        void getData(unsigned char tableData[16]);
        unsigned char getOctetSecurite();
        unsigned char checkEmissionNormaleOuReception();
        unsigned char getPriorite();
        unsigned char getNombreOctetsData();
        unsigned char calculerChecksum();
};

/* unsigned char CTrameKNX::getNombreOctetsData()
{
    //nothing for now
}

unsigned char CTrameKNX::m_TrameEnTableau()
{
    return 0;
}

unsigned char CTrameKNX::m_nombreOctetsMax()
{
    return 0;
}

unsigned char CTrameKNX::m_octetControle()
{
    return 0;
}

unsigned short int CTrameKNX::m_adresseDestinataire()
{
    return 0;
}

unsigned char CTrameKNX::m_octet_SiAdresseGroupe_CompteurRoutage_longueurData()
{
    return 0;
}

unsigned char CTrameKNX::m_nombreOctetsData()
{
    return 0;
}

unsigned char CTrameKNX::m_octetSecurite()
{
    return 0;
}

unsigned char CTrameKNX::m_emissionNormaleOuRepetition()
{
    return 0;
}

unsigned char CTrameKNX::m_priorite()
{
    return 0;
}

void CTrameKNX::seeTrameEnTableau(unsigned char trameEnTableau[6])
{
}

unsigned char CTrameKNX::getOctetControle()
{
    return 0;
}

unsigned short int CTrameKNX::getAdresseSource()
{
    return 0;
}

unsigned short int CTrameKNX::getAdresseDestinataire()
{
    return 0;
}

unsigned char CTrameKNX::getOctet_SiAdresseGroupe_CompteurRoutage_LongueurData()
{
    return 0;
}

void CTrameKNX::getData(unsigned char tableData[16])
{
}

unsigned char CTrameKNX::getOctetSecurite()
{
    return 0;
}

unsigned char CTrameKNX::checkEmissionNormaleOuReception()
{
    return 0;
}

unsigned char CTrameKNX::getPriorite()
{
    return 0;
}

unsigned char CTrameKNX::getNombreOctetsData()
{
    return 0;
}

*/