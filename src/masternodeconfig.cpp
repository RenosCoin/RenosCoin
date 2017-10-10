
#include "net.h"
#include "masternodeconfig.h"
#include "util.h"

CMasternodeConfig masternodeConfig;

void CMasternodeConfig::add(std::string alias, std::string ip, std::string privKey, std::string txHash, std::string outputIndex) {
    CMasternodeEntry cme(alias, ip, privKey, txHash, outputIndex);
    entries.push_back(cme);
}

bool CMasternodeConfig::read(boost::filesystem::path path) {
    boost::filesystem::ifstream streamConfig(GetMasternodeConfigFile());
    if (!streamConfig.good()) {
        return true; // No masternode.conf file is OK
    }

    for(std::string line; std::getline(streamConfig, line); )
    {
        if(line.empty()) {
            continue;
        }
        std::istringstream iss(line);
        std::string alias, ip, privKey, txHash, outputIndex;
        if (!(iss >> alias >> ip >> privKey >> txHash >> outputIndex)) {
            LogPrintf("Could not parse masternode.conf line: %s\n", line.c_str());
            streamConfig.close();
            return false;
        }

/*        if(CService(ip).GetPort() != 19999 && CService(ip).GetPort() != 9999)  {
            strErr = "Invalid port (must be 9999 for mainnet or 19999 for testnet) detected in masternode.conf: " + line;
            streamConfig.close();
            return false;
        }*/
        if (!(CService(ip).IsIPv4() && CService(ip).IsRoutable())) {
            LogPrintf("Invalid Address detected in masternode.conf: %s (IPV4 ONLY) \n", line.c_str());
            streamConfig.close();
            return false;
        }

        add(alias, ip, privKey, txHash, outputIndex);
    }

    streamConfig.close();
    return true;
}
