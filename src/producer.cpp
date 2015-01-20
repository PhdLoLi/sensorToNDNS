/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/**
 * Copyright (c) 2013-2014 Regents of the University of California.
 *
 * This file is part of ndn-cxx library (NDN C++ library with eXperimental eXtensions).
 *
 * ndn-cxx library is free software: you can redistribute it and/or modify it under the
 * terms of the GNU Lesser General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later version.
 *
 * ndn-cxx library is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
 * PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.
 *
 * You should have received copies of the GNU General Public License and GNU Lesser
 * General Public License along with ndn-cxx, e.g., in COPYING.md file.  If not, see
 * <http://www.gnu.org/licenses/>.
 *
 * See AUTHORS.md for complete list of ndn-cxx authors and contributors.
 *
 * @author Ilya Moiseenko iliamo@ucla.edu
 */

#include <ndn-cxx/contexts/producer-context.hpp>
#include "producer-callback.hpp"
#include <ctime>

// Enclosing code in ndn simplifies coding (can also use `using namespace ndn`)
namespace ndn {
// Additional nested namespace could be used to prevent/limit name contentions

int
main(int argc, char** argv)
{

  time_t time_start;

//  Name sensorPrefix("/example/data/3");
  Name sensorPrefix("/ndn/edu/ucla/lijing/cpu/temp");
    
  ProducerCallback proCB;

  Producer* sensorProducer = new Producer(sensorPrefix);
    
  proCB.setProducer(sensorProducer); // needed for some callback functionality
    
  //setting callbacks
  sensorProducer->setContextOption(INTEREST_ENTER_CNTX,
                    (ConstInterestCallback)bind(&ProducerCallback::processIncomingInterest, &proCB, _1));
                      
  sensorProducer->setContextOption(INTEREST_TO_PROCESS,
                    (ConstInterestCallback)bind(&ProducerCallback::processInterest, &proCB, _1));

  sensorProducer->setContextOption(DATA_LEAVE_CNTX,
                    (ConstDataCallback)bind(&ProducerCallback::processOutgoingData, &proCB, _1));
    
  //listening
//  sensorProducer->setup();

  while(1)
  {

    CPUTemp cputemp; 
    cputemp.SMCOpen();
    double temp = cputemp.SMCGetTemperature(SMC_KEY_CPU_TEMP); 
   
    cputemp.SMCClose();
  
    time_t time_now = std::time(0);
    std::string content = std::to_string(temp) ; //"RELIABLE ECHO z";
  
    std::string time_now_str = std::ctime(&time_now);
    std::cout << "Now time: " << time_now_str << std::endl;
  
    std::stringstream ss;
    ss << time_now;
  //  std::string tt= time_now;
  //  unsigned long t = time_now;
//    std::cout << time_now << " seconds since 01-Jan-1970\n" << std::endl;
    sensorProducer->produce(Name(ss.str()), (uint8_t*)content.c_str(), content.size());
    printf("%0.1f°C\n",temp);
    printf("------------------------------------------------------------------- END\n\n\n");
      
    sleep(10); // because setup() is non-blocking
  }
  
  return 0;
}

} // namespace ndn

int
main(int argc, char** argv)
{
  return ndn::main(argc, argv);
}
