#include <curlpp/Options.hpp>
#include <curlpp/Easy.hpp>
#include <iostream>
#include "interact.h"
#include "helpers/json.hpp"

using nlohmann::json;

namespace NotAgarIOController {

    void Interact::move_blob(Player * player, std::string blobColor, std::string direction, unsigned int distance) {
        // Making the payload
        std::stringstream jsonPayload;
        jsonPayload << "{ \"blob\": \"" << blobColor << "\", \"direction\": \"" << direction << "\", \"distance\": " << distance << " }" << std::endl;

        //Using curlpp to send HTTP request
        curlpp::Easy post;
        std::string url = "http://localhost:3000/move/" + player->get_username();
        std::cout << "Moving blob " << blobColor << " from player " << player->get_username() << " " << direction << " with a distance of " << distance << "..." << std::endl;
        std::list<std::string> header;
        header.push_back("Content-Type: application/json; charset=utf-8");
        std::ostringstream post_result;
        post.setOpt(new curlpp::options::Url(url));
        post.setOpt(new curlpp::options::HttpHeader(header));
        post.setOpt(new curlpp::options::PostFields(jsonPayload.str()));
        post.setOpt(new curlpp::options::PostFieldSize(jsonPayload.str().length()));
        post.setOpt(new curlpp::options::WriteStream(&post_result));
        post.perform();
    }

    void Interact::shoot_blob(Player * currentPlayer, std::string playerBlob, std::string enemyPlayer, std::string enemyBlob) {
        // Making the payload
        std::stringstream jsonPayload;
        jsonPayload << "{ \"target\": { \"player\": \"" << enemyPlayer << "\", \"blob\": \"" << enemyBlob << "\"}, \"source\": { \"player\": \"" << currentPlayer->get_username() << "\", \"blob\": \"" << playerBlob << "\"} }" << std::endl;

        //Using curlpp to send HTTP request
        curlpp::Easy post;
        std::string url = "http://localhost:3000/shoot";
        std::cout << "Shooting blob " << enemyBlob << " from player " << enemyPlayer << ", from your " << playerBlob << "..." << std::endl;
        std::list<std::string> header;
        header.push_back("Content-Type: application/json; charset=utf-8");
        std::ostringstream post_result;
        post.setOpt(new curlpp::options::Url(url));
        post.setOpt(new curlpp::options::HttpHeader(header));
        post.setOpt(new curlpp::options::PostFields(jsonPayload.str()));
        post.setOpt(new curlpp::options::PostFieldSize(jsonPayload.str().length()));
        post.setOpt(new curlpp::options::WriteStream(&post_result));
        post.perform();
    }



};