import React, { Component } from 'react';
import { connect } from 'react-redux';
import { setSelectedPart } from "./../../actions"
import Description from "./container/Description";

class Part extends Component {
  constructor(props) {
    super(props);
    this.handleClick = this.handleClick.bind(this);
  }

  handleClick() {
    this.props.dispatch(setSelectedPart(this.props.part))
  }

  render(){
    return(
      <div className={"panel panel-default " + (this.props.selected ? "panel-primary" : "")}>
        <div className="panel-heading">
          <h3
            className="panel-title"
            onClick={this.handleClick}
          >
              Part {this.props.part.id} description
          </h3>
        </div>
        <div className="panel-body">
          <Description part={this.props.part} />
        </div>
      </div>
    );
  }
}

export default connect()(Part);
