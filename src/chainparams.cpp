// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "assert.h"

#include "chainparams.h"
#include "main.h"
#include "util.h"

#include <boost/assign/list_of.hpp>

using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

//
// Main network
//

// Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress> &vSeedsOut, const SeedSpec6 *data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7*24*60*60;
    for (unsigned int i = 0; i < count; i++)
    {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

class CMainParams : public CChainParams {
public:
    CMainParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0xaa;
        pchMessageStart[1] = 0xa3;
        pchMessageStart[2] = 0xb2;
        pchMessageStart[3] = 0xc4;
        vAlertPubKey = ParseHex("");
        nDefaultPort = 57155;
        nRPCPort = 57154;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 20);

        // Build the genesis block. Note that the output of the genesis coinbase cannot
        // be spent as it did not originally exist in the database.
        //
        //CBlock(hash=000001faef25dec4fbcf906e6242621df2c183bf232f263d0ba5b101911e4563, ver=1, hashPrevBlock=0000000000000000000000000000000000000000000000000000000000000000, hashMerkleRoot=12630d16a97f24b287c8c2594dda5fb98c9e6c70fc61d44191931ea2aa08dc90, nTime=1393221600, nBits=1e0fffff, nNonce=164482, vtx=1, vchBlockSig=)
        //  Coinbase(hash=12630d16a9, nTime=1393221600, ver=1, vin.size=1, vout.size=1, nLockTime=0)
        //    CTxIn(COutPoint(0000000000, 4294967295), coinbase 00012a24323020466562203230313420426974636f696e2041544d7320636f6d6520746f20555341)
        //    CTxOut(empty)
        //  vMerkleTree: 12630d16a9
        const char* pszTimestamp = "New genesis for Coinswap of RENOS June/17";
        std::vector<CTxIn> vin;
        vin.resize(1);
        vin[0].scriptSig = CScript() << 0 << CBigNum(42) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        std::vector<CTxOut> vout;
        vout.resize(1);
        vout[0].SetEmpty();
        CTransaction txNew(1, 1497040584, vin, vout, 0);
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime    = 1497040584;
        genesis.nBits    = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce   = 213861;                                        

        hashGenesisBlock = genesis.GetHash(); 
   
        assert(hashGenesisBlock == uint256("0x00000e590857f6bf83e3ae07b56528e47565115465f9d4e8ead2c5bffb1a9edc"));
        assert(genesis.hashMerkleRoot == uint256("0xb43b9c01703081ea07d54e271471e7100364535cf55e38763761e384d27970af"));

       	vSeeds.push_back(CDNSSeedData("seed1", "137.74.193.204"));
	vSeeds.push_back(CDNSSeedData("seed2", "137.74.193.204"));
	vSeeds.push_back(CDNSSeedData("seed3", "198.50.180.192"));
	vSeeds.push_back(CDNSSeedData("seed4", "137.74.193.204"));
	vSeeds.push_back(CDNSSeedData("seed5", "137.74.193.204"));
	vSeeds.push_back(CDNSSeedData("seed6", "45.32.196.193"));
	vSeeds.push_back(CDNSSeedData("seed7", "45.32.164.109"));
	vSeeds.push_back(CDNSSeedData("seed8", "45.77.5.93"));
	vSeeds.push_back(CDNSSeedData("seed9", "149.56.128.2"));
	vSeeds.push_back(CDNSSeedData("seed10", "2a01:7e01::f03c:91ff:fe7b:8e41"));
	vSeeds.push_back(CDNSSeedData("seed11", "45.77.58.26"));
	vSeeds.push_back(CDNSSeedData("seed12", "45.77.37.208"));
	vSeeds.push_back(CDNSSeedData("seed13", "174.67.252.25"));
	vSeeds.push_back(CDNSSeedData("seed14", "79.137.34.194"));
	vSeeds.push_back(CDNSSeedData("seed15", "144.217.166.140"));
	vSeeds.push_back(CDNSSeedData("seed16", "2001:bc8:4700:2000::3e39"));
	vSeeds.push_back(CDNSSeedData("seed17", "104.238.184.213"));
	vSeeds.push_back(CDNSSeedData("seed18", "93.186.193.158"));
	vSeeds.push_back(CDNSSeedData("seed19", "51.15.52.23"));
	vSeeds.push_back(CDNSSeedData("seed20", "198.50.171.20"));
	vSeeds.push_back(CDNSSeedData("seed21", "147.135.233.42"));
	vSeeds.push_back(CDNSSeedData("seed22", "45.79.216.189"));
	vSeeds.push_back(CDNSSeedData("seed23", "2600:3c02::f03c:91ff:fe3e:dbbb"));
	vSeeds.push_back(CDNSSeedData("seed24", "45.63.68.182"));
	vSeeds.push_back(CDNSSeedData("seed25", "90.215.122.71"));
	vSeeds.push_back(CDNSSeedData("seed26", "82.43.204.158"));
	vSeeds.push_back(CDNSSeedData("seed27", "5.189.142.181"));
	vSeeds.push_back(CDNSSeedData("seed28", "2001:4ca0:0:fe00:0:5efe:a96:caa4"));
	vSeeds.push_back(CDNSSeedData("seed29", "193.90.142.13"));
	vSeeds.push_back(CDNSSeedData("seed30", "35.165.42.90"));
	vSeeds.push_back(CDNSSeedData("seed31", "2.62.187.203"));
	vSeeds.push_back(CDNSSeedData("seed32", "192.210.128.100"));
	vSeeds.push_back(CDNSSeedData("seed33", "2a02:f680:1:1100::60d2"));
	vSeeds.push_back(CDNSSeedData("seed34", "80.89.233.124"));
	vSeeds.push_back(CDNSSeedData("seed35", "203.59.230.190"));
	vSeeds.push_back(CDNSSeedData("seed36", "222.5.183.201"));
	vSeeds.push_back(CDNSSeedData("seed37", "104.237.153.253"));
	vSeeds.push_back(CDNSSeedData("seed38", "147.135.233.45"));
	vSeeds.push_back(CDNSSeedData("seed39", "2a01:7e01::f03c:91ff:fe92:d170"));
	vSeeds.push_back(CDNSSeedData("seed40", "172.104.86.169"));
	vSeeds.push_back(CDNSSeedData("seed41", "45.63.89.184"));
	vSeeds.push_back(CDNSSeedData("seed42", "2600:3c01::f03c:91ff:fed4:f07"));
	vSeeds.push_back(CDNSSeedData("seed43", "108.61.197.30"));
	vSeeds.push_back(CDNSSeedData("seed44", "45.77.80.196"));
	vSeeds.push_back(CDNSSeedData("seed45", "147.135.233.33"));
	vSeeds.push_back(CDNSSeedData("seed46", "2400:8902::f03c:91ff:fe3e:dbbf"));
	vSeeds.push_back(CDNSSeedData("seed47", "147.135.233.35"));
	vSeeds.push_back(CDNSSeedData("seed48", "2607:fea8:131f:f75a::7"));
	vSeeds.push_back(CDNSSeedData("seed49", "2001:0:9d38:6ab8:20a5:1a6c:fdc1:4434"));
	vSeeds.push_back(CDNSSeedData("seed50", "45.32.130.36"));
	vSeeds.push_back(CDNSSeedData("seed51", "45.77.82.231"));
	vSeeds.push_back(CDNSSeedData("seed52", "2001:0:9d38:6abd:34db:f25:899b:5608"));
	vSeeds.push_back(CDNSSeedData("seed53", "2001:0:9d38:90d7:3ce3:11d9:b08f:2a28"));
	vSeeds.push_back(CDNSSeedData("seed54", "2001:0:9d38:953c:10df:211c:41b4:9198"));


		
        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,60);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,28);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,150);
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x88)(0xB2)(0x1E).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x88)(0xAD)(0xE4).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        nLastPOWBlock = 6000;
    }

    virtual const CBlock& GenesisBlock() const { return genesis; }
    virtual Network NetworkID() const { return CChainParams::MAIN; }

    virtual const vector<CAddress>& FixedSeeds() const {
        return vFixedSeeds;
    }
protected:
    CBlock genesis;
    vector<CAddress> vFixedSeeds;
};
static CMainParams mainParams;


//
// Testnet
//

class CTestNetParams : public CMainParams {
public:
    CTestNetParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0xa1;
        pchMessageStart[1] = 0x79;
        pchMessageStart[2] = 0xa4;
        pchMessageStart[3] = 0xa2;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 16);
        vAlertPubKey = ParseHex("");
        nDefaultPort = 57255;
        nRPCPort = 57254;
        strDataDir = "testnet";

        // Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nBits  = 1497040584;
        genesis.nNonce = 213861;
		
        assert(hashGenesisBlock == uint256("0x00000e590857f6bf83e3ae07b56528e47565115465f9d4e8ead2c5bffb1a9edc"));

        vFixedSeeds.clear();
        vSeeds.clear();

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,111);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,196);
        base58Prefixes[SECRET_KEY]     = std::vector<unsigned char>(1,229);
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x35)(0x87)(0xCF).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x35)(0x83)(0x94).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

        nLastPOWBlock = 0x7fffffff;
    }
    virtual Network NetworkID() const { return CChainParams::TESTNET; }
};
static CTestNetParams testNetParams;


static CChainParams *pCurrentParams = &mainParams;

const CChainParams &Params() {
    return *pCurrentParams;
}

void SelectParams(CChainParams::Network network) {
    switch (network) {
        case CChainParams::MAIN:
            pCurrentParams = &mainParams;
            break;
        case CChainParams::TESTNET:
            pCurrentParams = &testNetParams;
            break;
        default:
            assert(false && "Unimplemented network");
            return;
    }
}

bool SelectParamsFromCommandLine() {
    
    bool fTestNet = GetBoolArg("-testnet", false);
    
    if (fTestNet) {
        SelectParams(CChainParams::TESTNET);
    } else {
        SelectParams(CChainParams::MAIN);
    }
    return true;
}
