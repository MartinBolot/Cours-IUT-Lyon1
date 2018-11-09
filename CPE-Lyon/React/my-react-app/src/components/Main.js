import React, { Component } from 'react';
import '../App.css';
import '../lib/bootstrap-3.3.7-dist/css/bootstrap.min.css';
import LeftSide from "./LeftSide/LeftSide";
import * as jsonSource from "../sources/robots";

class Main extends Component {
  render() {
    return (
      <div className="container-fluid">
        <div className="row">
          <h1>Welcome to robot shop</h1>
        </div>
        <div className="row">
            <div className="col-md-4 col-lg-4" >
              <LeftSide robots={jsonSource.robots} />
            </div>
            <div className="col-md-4 col-lg-4" ></div>
            <div className="col-md-4 col-lg-4" ></div>
        </div>
      </div>
    );
  }
}

export default Main;
