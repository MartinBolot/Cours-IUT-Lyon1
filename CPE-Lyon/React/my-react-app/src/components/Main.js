import React, { Component } from 'react';
import { connect } from 'react-redux';
import '../App.css';
import '../lib/bootstrap-3.3.7-dist/css/bootstrap.min.css';
import LeftSide from "./LeftSide/LeftSide";
import MiddleSide from "./MiddleSide/MiddleSide";
import RightSide from "./RightSide/RightSide";
import * as jsonSource from "../sources/robots_parts";

class Main extends Component {
  render() {
    let filteredParts;
    let selectedPart;

    if(this.props.selectedRobotId) {
      const robot = jsonSource.robots.filter((robot) => {
        return robot.id === this.props.selectedRobotId;
      })[0];
      filteredParts = jsonSource.parts.filter((part) => {
        // does the robots have this part ?
        return (
          robot.parts ? robot.parts.includes(part.id) : false
        );
      });
    }

    if(this.props.selectedPartId) {
      selectedPart = jsonSource.parts.filter((part) => {
        return part.id === this.props.selectedPartId;
      })[0];
    }

    return (
      <div className="container-fluid">
        <div className="row">
          <h1>Welcome to robot shop</h1>
        </div>
        <div className="row">
            <div className="col-md-4 col-lg-4">
              <LeftSide
                robots={jsonSource.robots}
                selectedRobotId={this.props.selectedRobotId}
              />
            </div>
            <div className="col-md-4 col-lg-4">
              <MiddleSide
                parts={filteredParts}
                selectedPartId={this.props.selectedPartId}
              />
            </div>
            <div className="col-md-4 col-lg-4" >
              <RightSide
                part={selectedPart}
                selectedPartId={this.props.selectedPartId}
              />
            </div>
        </div>
      </div>
    );
  }
}

const mapStateToProps = (state, ownprops) => {
  return {
    selectedRobotId: state.robotReducer.id,
    selectedPartId: state.partReducer.id
  }
};

export default connect(mapStateToProps)(Main);
