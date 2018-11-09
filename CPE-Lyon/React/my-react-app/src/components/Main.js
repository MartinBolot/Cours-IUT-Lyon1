import React, { Component } from 'react';
import '../App.css';
import '../lib/bootstrap-3.3.7-dist/css/bootstrap.min.css';
import LeftSide from "./LeftSide/LeftSide";
import MiddleSide from "./MiddleSide/MiddleSide";
import * as jsonSource from "../sources/robots_parts";

class Main extends Component {
  constructor(props) {
    super(props);
    this.state = {
      parts: jsonSource.parts,
      selectedId: null,
    };
    this.handleLeftSideClick = this.handleLeftSideClick.bind(this);
  }

  handleLeftSideClick(id) {
    // get the robot having the right id
    const robot = jsonSource.robots.filter((robot) => {
      return robot.id === id;
    })[0];

    // update according to this robot parts
    const filteredParts = jsonSource.parts.filter((part) => {
      // does the robots have this part ?
      return (
        robot.parts ? robot.parts.includes(part.id) : false
      );
    });

    this.setState({
      parts: filteredParts,
      selectedId: id,
    });
  }

  render() {
    return (
      <div className="container-fluid">
        <div className="row">
          <h1>Welcome to robot shop</h1>
        </div>
        <div className="row">
            <div className="col-md-4 col-lg-4">
              <LeftSide
                robots={jsonSource.robots}
                selectedId={this.state.selectedId}
                handleLeftSideClick={this.handleLeftSideClick}
              />
            </div>
            <div className="col-md-4 col-lg-4">
              <MiddleSide parts={this.state.parts} />
            </div>
            <div className="col-md-4 col-lg-4" ></div>
        </div>
      </div>
    );
  }
}

export default Main;
