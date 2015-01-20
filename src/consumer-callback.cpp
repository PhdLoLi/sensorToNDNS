/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/**
 * Copyright (c) 2014 Regents of the University of California.
 *
 * @author Lijing Wang phdloli@ucla.edu
 */

#include "consumer-callback.hpp"
#include <string>
#include <pthread.h>
#include <ctime>

// Enclosing code in ndn simplifies coding (can also use `using namespace ndn`)
namespace ndn {
// Additional nested namespace could be used to prevent/limit name contentions

  int times = 0;

  ConsumerCallback::ConsumerCallback()
  {
  }
  
  void
  ConsumerCallback::processPayload(const uint8_t* buffer, size_t bufferSize)
  {
//    std::cout << "times processPayload " << std::dec << times <<std::endl;
//    std::cout << "bufferSize " << bufferSize <<std::endl;
    std::cout << "Temp " << buffer << " °C"<<std::endl;
    times ++;
  }

  void
  ConsumerCallback::processData(Data& data)
  {
    std::cout << "DATA IN CNTX Name: " << data.getName()  << std::endl;
    //<< "FinalBlockId: " <<data.getFinalBlockId() << std::endl;
  }
  
  bool
  ConsumerCallback::verifyData(Data& data)
  {
    return true;
  }
  
  void
  ConsumerCallback::processConstData(const Data& data)
  {}
  
  void
  ConsumerCallback::processLeavingInterest(Interest& interest)
  {
    std::cout << "LEAVES " << interest.toUri() << std::endl;
//    std::cout << "LEAVES name " << interest.getName() << std::endl;
  }  
} // namespace ndn
