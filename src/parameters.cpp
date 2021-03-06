#include <iostream>
#include "parameters.h"
#include "time_fun.h"

// constructor
Parameters::Parameters(json_t* root) {
  // strategy and global parameters
  spreadEntry = json_real_value(json_object_get(root, "SpreadEntry"));
  spreadTarget = json_real_value(json_object_get(root, "SpreadTarget"));
  maxLength = json_integer_value(json_object_get(root, "MaxLength"));
  priceDeltaLim = json_real_value(json_object_get(root, "PriceDeltaLimit"));
  aggressiveVolume = json_boolean_value(json_object_get(root, "AggressiveVolume"));
  trailingLim = json_real_value(json_object_get(root, "TrailingSpreadLim"));
  infoOnly = json_boolean_value(json_object_get(root, "InfoOnly"));
  verbose = json_boolean_value(json_object_get(root, "Verbose"));

  // exchanges credentials
  bitfinexApi = json_string_value(json_object_get(root, "BitfinexApiHead"));
  bitfinexSecret = json_string_value(json_object_get(root, "BitfinexKey"));
  okCoinApi = json_string_value(json_object_get(root, "OkCoinApiKey"));
  okCoinSecret = json_string_value(json_object_get(root, "OkCoinSecretKey"));
  bitstampClientId = json_string_value(json_object_get(root, "BitstampClientId"));
  bitstampApi = json_string_value(json_object_get(root, "BitstampApiKey"));
  bitstampSecret = json_string_value(json_object_get(root, "BitstampSecretKey"));
  geminiApi = json_string_value(json_object_get(root, "GeminiApiKey"));
  geminiSecret = json_string_value(json_object_get(root, "GeminiSecretKey"));
  krakenApi = json_string_value(json_object_get(root, "KrakenApiKey"));
  krakenSecret = json_string_value(json_object_get(root, "KrakenSecretKey"));
  btceApi = json_string_value(json_object_get(root, "BTCeApiKey"));
  btceSecret = json_string_value(json_object_get(root, "BTCeSecretKey"));
  sevennintysixApi = json_string_value(json_object_get(root, "SevenNintySixApiKey"));
  sevennintysixSecret = json_string_value(json_object_get(root, "SevenNintySixSecretKey"));
    
  // email parameters
  sendEmail = json_boolean_value(json_object_get(root, "SendEmail"));
  senderAddress = json_string_value(json_object_get(root, "SenderAddress"));
  senderUsername = json_string_value(json_object_get(root, "SenderUsername"));
  senderPassword = json_string_value(json_object_get(root, "SenderPassword"));
  smtpServerAddress = json_string_value(json_object_get(root, "SmtpServerAddress"));
  receiverAddress = json_string_value(json_object_get(root, "ReceiverAddress"));
}


// add an exchange
void Parameters::addExchange(std::string n, double f, bool h, bool m) {
  exchName.push_back(n);
  fees.push_back(f);
  hasShort.push_back(h);
  isImplemented.push_back(m);
}


// returns number of exchanges
int Parameters::nbExch() const {
  return exchName.size();
}

