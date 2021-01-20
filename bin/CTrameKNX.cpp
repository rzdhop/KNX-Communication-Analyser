//PLEASE DO NOT USE THIS FILE before veryfing.

class CTrameKNX {
    private:
        unsigned char m_TrameEnTableau;
        unsigned char m_nombreOctetsMax;
        unsigned char m_octetControle;
        unsigned short int m_adresseDestinataire;
        unsigned char m_octet_SiAdresseGroupe_CompteurRoutage_longueurData;
        unsigned char m_nombreOctetsData;
        unsigned char m_octetSecurite;
        unsigned char m_emissionNormaleOuRepetition;
        unsigned char m_priorite;
    public:
        //CTrameKNX()
        //CTrameKNX() char *trameBruteKNX
        //~CTrameKNX()
        void (unsigned char trameEnTableau[]);
        unsigned char getOctetControle();
        unsigned short int getAdresseSource();
        unsigned short int getAdresseDestinataire();
        unsigned char getOctet_SiAdresseGroupe_CompteurRoutage_LongueurData();
        void getData(unsigned char tableData[16]);
        unsigned char getOctetSecurite();
        unsigned char checkEmissionNormaleOuReception();
        unsigned char getPriorite();
        unsigned char getNombreOctetsData();
        unsigned char calculerChecksum()
};